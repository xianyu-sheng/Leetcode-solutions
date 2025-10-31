cd/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> rel;
    vector<int> path;
    //                          需要遍历的邻接表  遍历起点  遍历的终点
    void dfs(const vector<vector<int>>& graph,int x,int n){
        //结束递归
        if(x==n){
            rel.push_back(path);
            return;
        }
        for(int i:graph[x]){
            //处理当前节点
            path.push_back(i);
            dfs(graph,i,n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /*
            题目理解：使用深度优先搜索进行搜索  这是一个邻接表
        */
        path.push_back(0);
        dfs(graph,0,graph.size()-1);
        return rel;
    }
};
// @lc code=end

