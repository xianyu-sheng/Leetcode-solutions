/*
 * @lc app=leetcode.cn id=1970 lang=cpp
 *
 * [1970] 你能穿过矩阵的最后一天
 */

// @lc code=start
class Solution {
public:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool CanCross(int day,const vector<vector<int>>& cells,int row,int col){
        //1.先构建全陆地的数组
        vector<vector<int>> gird(row+1,vector<int>(col+1,0));
        //然后将他们染为水域
        for(int i=0;i<day;i++){
            gird[cells[i][0]][cells[i][1]]=1;
        }
        //然后这里使用广度优先搜索
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(row+1,vector<bool>(col+1,false));
        //然后往que里添加第一行 可以作为起始的点
        for(int i=1;i<=col;i++){
            if(gird[1][i]==0){
                que.push({1,i});
                visited[1][i]=true;
            }
        }
        //然后开始官渡优先搜索
        while(!que.empty()){
            auto [r,c]=que.front();que.pop();
            if(r==row)  return true;//说明可以走通
            //然后还没有达到的话 就开始四处走
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];

                //边界检查以及是否是陆地
                if(nr<1 || nr > row || nc<1 || nc>col || gird[nr][nc]==1)   continue;
                //然后看是否访问过了
                if(gird[nr][nc]==0 && visited[nr][nc]==false){
                    visited[nr][nc]=true;
                    que.push({nr,nc});
                }
            }
        }
        return  false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        /*
            =这里需要用到二分+递归   取cells的一半mid  然后构建数组 如果发现在第mid天还能过 那么我就去找mid后的天数
        */
        int left=0;
        int right=cells.size();
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(CanCross(mid,cells,row,col)){
                //还可以过 那么就往后看
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};
// @lc code=end

