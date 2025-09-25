/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];  // 只要今天比昨天贵就“买卖”
        }
        return ans;
    }
};
// @lc code=end

