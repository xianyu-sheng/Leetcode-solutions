class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        /*
            解题思路：这个题的思路，我认为就是动态规划，三种物品，分数就是价值，然后花费就是体积，然后需要达到(m-1,n-1)
            并且背包的体积需要满足为k
            但是这里用贪心或许更佳  每次我们只能向右或下移动 那么就选择第一，在花费没超过K的时候，每次选择尽量多的分数走，如果分数接近k了 就尽量按小的走
            使用动态规划来解决这个问题 dp[i][j][c]当走到grid[i][j]时，花费c的时候最大的得分
        */
        int  m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        //初始化起点
        int  start_val=grid[0][0];
        int start_cost=(start_val==0)?0:1;
        int start_score=(start_val==0)?0:(start_val==1)?1:2;
        if(start_cost<=k){
            dp[0][0][start_cost]=start_score;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                //然后来继续cost
                int val=grid[i][j];
                int cost=(val==0)?0:1;
                int score=(val==0)?0:(val==1)?1:2;

                for(int c=cost;c<=k;c++){
                    //从上方转移
                    if(i>0 && dp[i-1][j][c-cost]!=-1){
                        dp[i][j][c]=max(dp[i][j][c],dp[i-1][j][c-cost]+score);
                    }
                    if(j>0 && dp[i][j-1][c-cost]!=-1){
                         dp[i][j][c]=max(dp[i][j][c],dp[i][j-1][c-cost]+score);
                    }
                }
            }
        }
        //然后来进行遍历到m-1 n-1  这里的最大得分
        int  ans=-1;
        for(int c=0;c<=k;c++){
            if(dp[m-1][n-1][c]!=-1){
                ans=max(ans,dp[m-1][n-1][c]);
            }
        }
        return ans;
    }
};©leetcode