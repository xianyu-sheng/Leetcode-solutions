/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    /*
        解题思路：在这个题中，我们可以看到的是，他除了需要通过股票的涨幅来决定是否要买卖股票，同时这里还需要根据前一天的状态，比如前一天已经卖出股票了 那么相应的在今天的我们就需要考虑前一天是否刚售出  如果刚售出 那么我们今天就应该保持原样 否则 我们在考虑是否买入  这里可以查看前一天的利润与上前天的不持有股票的利润就可以知道是否当天需要冷冻
    */
        if (prices.empty()) return 0;

        int hold = -prices[0];   // 持有股票
        int sold = 0;            // 刚卖出
        int rest = 0;            // 空闲（可买入）

        for (int i = 1; i < prices.size(); ++i) {
            int new_hold = max(hold, rest - prices[i]);     // 继续持有 或 买入
            int new_sold = hold + prices[i];                // 卖出
            int new_rest = max(rest, sold);                 // 恢复空闲

            hold = new_hold;
            sold = new_sold;
            rest = new_rest;
        }

        // 最后一天，肯定不持股才能利润最大
        return max(sold, rest);
    }
};
// @lc code=end

