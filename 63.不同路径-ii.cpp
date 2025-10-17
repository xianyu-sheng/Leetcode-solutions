/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*
            解题思路：相比较于不同路径I  这个题还要进行绕障 我的初步理解是  动规五部曲
            1、确定dp[i][j]含义及下标含义：代表到某某位置，有多少条路径
            2、递推公式:dp[i][j]=dp[i-1][j]+dp[i][j-1]
            3、dp数组如何初始化？--->这里应该分为两种情况进行初始化，相比于不同路径I  对于第一行第一列的中如果有障碍，那么其dp[i][j]=0----->不对，应该是如果在初始化的时候 发现路上有障碍 那么这条路的障碍后面都是不通的啊
            4、原遍历顺序
        */
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        //初始化dp数组
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                for(int j=i;j<m;j++){
                    dp[j][0]=0;
                }
                break;
            }
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                for(int j=i;j<n;j++){
                    dp[0][j]=0;
                }
                break;
            }
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

