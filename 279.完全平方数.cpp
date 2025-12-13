/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        /*
            完全平方数：与后面的最小硬币数的解法一样
        */
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=1;j*j <=i ;j++){
                if(i>=j*j && dp[i-j*j]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-j*j]+1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

