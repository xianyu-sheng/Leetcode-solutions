/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    //编写并查集的四个函数
    int n=1005;
    vector<int> father=vector(n,0);
    //初始化
    void init(){
        for(int i=0;i<n;i++){
            father[i]=i;
        }
    }
    //查找函数
    int find(int u){
        return u==father[u]?father[u]:(father[u]=find(father[u]));
    }
    //查看是否是在同一个并查集中
    bool isSame(int u,int v){
        u=find(u);
        v=find(v);
        return u==v;
    }
    //加入到并查集中
    void join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)    return;
        father[u]=v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            检查冗余链接的最好的方法就是使并查集来进行检验，如果两个节点监测到属于一个跟节点了  那么就代表有冗余链接
            并查集一共有四个函数
            init()   find() join() issame()等四个函数
        */
        //先初始化
        init();
        //然后遍历edges
        for(int i=0;i<edges.size();i++){
            if(isSame(edges[i][0],edges[i][1])) return edges[i];
            else    join(edges[i][0],edges[i][1]);
        }
        return {};
    }
};
// @lc code=end

