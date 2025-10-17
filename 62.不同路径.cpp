/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            动态规划：每次只能向下或者向右移动一步，那么当前的状态应该来自于两种方式，要不就是别人向下移动来的
            要不就是向右移动来的

            动规五部曲：
            1、dp[i][j]含义与其下标含义：dp[i][j]代表到当前位置有多少条路径
            2、确定状态转移公式  dp[i][j]=dp[i-1][j]+dp[i][j-1]
            3、dp数组如何初始化----->第一行第一列除起始点全部置为1
            4、确定遍历顺序--------->两层for循环，分别从1开始遍历
        */
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        //将第一行第一列完成初始化
        for(int i=1;i<n;i++)
            dp[0][i]=1;
        for(int i=1;i<m;i++)
            dp[i][0]=1;
        //开始遍历其他位置
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

