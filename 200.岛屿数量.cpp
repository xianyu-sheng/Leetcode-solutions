/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
//深度优先搜索
class Solution {
public:
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    void  dfs(const vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y){
        //进行一个节点的四个方向上的搜索
        for(int i=0;i<4;i++){
            int next_x=x+dir[i][0];
            int next_y=y+dir[i][1];
            //判断是否已经遍历过了 或者是否超过了界限
            if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>=grid[0].size())   continue;
            if(!visited[next_x][next_y] && grid[next_x][next_y]=='1'){
                visited[next_x][next_y]=true;
                dfs(grid,visited,next_x,next_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        /*
            图论的运用：使用深度优先搜索进行遍历
        */
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        int rel=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    visited[i][j]=true;
                    rel++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return rel;
    }
};
//广度优先搜索
class Solution {
public:
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    void  Bfs(const vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y){
        //设置一个队列来进行取号
        queue<pair<int,int>> que;
        que.push({x,y});
        visited[x][y]=true;
        while(!que.empty()){
            //取数据
            pair<int,int> cur=que.front();que.pop();
            //然后就把取出来的这个点的周围搜完
            //进行一个节点的四个方向上的搜索
            for(int i=0;i<4;i++){
                int next_x=cur.first+dir[i][0];
                int next_y=cur.second+dir[i][1];
                //判断是否已经遍历过了 或者是否超过了界限
                if(next_x<0 || next_x>=grid.size() || next_y<0 || next_y>=grid[0].size())   continue;
                if(!visited[next_x][next_y] && grid[next_x][next_y]=='1'){
                    que.push({next_x,next_y});
                    visited[next_x][next_y]=true;
                }
            }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        /*
            图论的运用：使用深度优先搜索进行遍历
        */
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        int rel=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    rel++;
                    Bfs(grid,visited,i,j);
                }
            }
        }
        return rel;
    }
};
// @lc code=end

