/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0)    return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        //然后初始化  将奇数位置都置为-prices[0]
        for(int i=1;i<2*k;i+=2){
            dp[0][i]=-prices[0];
        }
        for(int i=1;i<prices.size();i++){
            for(int j=0;j<2*k-1;j+=2){
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};
/*
    本道题和买卖股票的最佳时机|||很像，只是从二次扩展到更灵活的K次，依然是使用二维数组
    来记录，K次买卖的情况
 */
// @lc code=end

