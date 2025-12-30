/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            求需要的最小分钟数，那么就是去求走的步数，而怎么走呢？每次走一段路 并且这里也需要进行记录 最后如果还有剩的孤岛也就是新鲜橘子 那么
            就退出-1  或者 就是满足的 直接返回步数
        */
        int dir[4][2]={1,0,0,1,-1,0,0,-1};
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<int,int>> que;

        int fresh=0;//统计新鲜橘子
        int time=0;//统计时间

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                //统计新鲜橘子 + 将第一层的腐烂的橘子加入进去
                if(grid[i][j]==1)   fresh++;
                if(grid[i][j]==2)   que.push({i,j});
            }
        }

        //然后开始进行层序遍历
        while(!que.empty() && fresh>0){
            int size=que.size();
            while(size--){
                pair<int,int> cur=que.front();que.pop();
                for(int i=0;i<4;i++){
                    int next_x=cur.first+dir[i][0];
                    int next_y=cur.second+dir[i][1];
                    //判断是否已经遍历过了 或者是否超过了界限
                    if(next_x<0 || next_x>=rows || next_y<0 || next_y>=cols)   continue;
                    //再来判断是否等于1
                    if(grid[next_x][next_y]==1){
                        grid[next_x][next_y]=2;
                        fresh--;
                        que.push({next_x,next_y});
                    }
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
};
// @lc code=end

