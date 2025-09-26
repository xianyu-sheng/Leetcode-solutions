/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            解题思路：还是构建一个只有两列   然后根据prices数组的大小构造的行数
            然后dp数组的第一列 代表不持有股票的最大利润  第二列代表持有股票的最大利润
                        不持有利润分为两种情况：1.你的前一天你就不持有股票
                                            2.你前一天还持有股票，但是今天决定卖了
                        持有股票的利润情况：1.前一天不持有股票，但是今天刚买入
                                        2.前一天就持有股票，现在继续持有
            但是如何来决定最多可以完成两笔交易呢？
        */
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};
// @lc code=end

