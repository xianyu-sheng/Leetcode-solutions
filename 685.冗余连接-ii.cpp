/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<int> father;
    //1.初始化
    void init(){
        for(int i=1;i<=n;i++){
            father[i]=i;
        }
    }
    //2.找根节点
    int find(int u){
        return u==father[u]?u:father[u]=find(father[u]);
    }
    //3.判断是否在同一个集合
    bool isSame(int u,int v){
        u=find(u);
        v=find(v);
        return u==v;
    }  
    //4.加入到并查集   将u->v的这条边加入进去
    void join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)    return;
        father[v]=u;
    }
    bool getAfterRomoveEdge(vector<vector<int>>& edges,int del_edge){
        //首先，初始化
        init();
        for(int i=0;i<edges.size();i++){
            if(i==del_edge) continue;
            if(isSame(edges[i][0],edges[i][1])) return false;
            //否则 就可以将其加入到并查集
            join(edges[i][0],edges[i][1]);
        }
        return true;
    }
    //如果没有入度为2的节点 那么就是直接找到构成环的边 直接删除
    vector<int> DelteEdge(vector<vector<int>>& edges){
        init();
        //然后倒序的遍历
        for(int i=0;i<edges.size();i++){
            //如果加入发现已经在同一个并查集里了 那么就直接返回这个边
            if(isSame(edges[i][0],edges[i][1])) return edges[i];
            join(edges[i][0],edges[i][1]);
        }
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*
            题目理解：这里有三种情况
            1.找到入度为2的节点，然后直接删除后出现的那条边
            2.入度为2的节点，但是我们只能删除特定的边，否则删完之后，就不能够构成一棵树了
            3.入度没有2的 但是构成了环，删除构成环的边就行

            //所以这个题的大概脉络就是，先统计所有的节点的入度，如果有入度为2的节点，就判断其删除后面的那条边是否还是树，如果还是
            那么就代表我们找对了  如果没有入度为2的节点，说明构成了环，我们应该找到构成环的边然后删除
        */

        //第一步，先统计是否有入度为2的节点
        n = edges.size();
        father.resize(n + 1); 
        vector<int> IN_degree(n+1,0);
        for(auto edge : edges)  IN_degree[edge[1]]++;
        //然后找到对应于这个入度为2的节点的两条边
        vector<int> vec;
        for(int i=edges.size()-1;i>=0;i--){
            if(IN_degree[edges[i][1]]==2){
                vec.push_back(i);
            }
        }
        //然后就准备看看删除这两条边中的那一条边之后  我们的树依旧还是树
        if(vec.size()>0){
            if(getAfterRomoveEdge(edges,vec[0])) return edges[vec[0]];
            else    return edges[vec[1]];
        }
        //否则就是环
        return DelteEdge(edges);
    }
};
// @lc code=end

