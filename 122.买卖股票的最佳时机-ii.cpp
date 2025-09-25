/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));

        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            // 不持有：要么昨天就不持，要么今天卖了
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            // 持有：要么昨天就持，要么今天买了
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

