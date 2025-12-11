class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            解题思路：找出一条从左上角到右下角的路径   [0,0]----->[m-1,n-1]
            每次只能向下或者向右移动一步----->每次比较下一步走哪里最小的 但是这样就变成了贪心算法了  这里我们应该选择动态规划
            算法  因为局部最优不代表全局最优

            动态规划五部曲：
            1.确定dp[i][j]的含义   即从0,0 出发 到达 i,j的最小路径之和
            2.确定动态规划的推导公式  dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
            3.初始化：第一行累加  第一列累加
            4.遍历顺序皆可
        */
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //然后初始化
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
        sum=0;
        for(int i=0;i<m;i++){
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        //然后开始推导
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};