/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //每一天有两个状态，持有股票的最大利润以及不持有股票的最大利润
        //在持有股票时，有两个状态：1.继续持有昨天的股票   2.今天新买股票
        //在不持有股票时，也有两个状态：1.昨天持有股票，但是今天准备售出，注意这里交易股票需要缴纳手续费  2.继续保持昨天不持有股票的状态
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //初始化第一天的状态
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<prices.size();i++){
            //进行状态的更新
            //对于持有股票时,可以选择继续持有昨天的股票还是买入新的股票
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            //对于不持有股票时候的状态，可以选择继续保持昨天不持有股票时的状态 或者是在今天卖出 不过对于卖出股票需要进行手续费的缴纳
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);
        }
        return dp[prices.size()-1][1];
    }
};
// @lc code=end

