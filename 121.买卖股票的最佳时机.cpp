/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //可以像上一题的树形dp那样，每一支股票，都有两个状态，被买入，被卖出
        //dp数组是这样的  一个大小为2的数组  第一个位置是买入的价格 第二位置就是需要迈出的价格
        vector<int> dp(2,0);
        dp[0]=prices[0];
        int max_value=0;//用一个变量来实时记录最大利润 当我们更新买入的时候 那么就同时要更新售出 价格
        for(int i=1;i<prices.size();i++){
            if(prices[i]<dp[0]){
                dp[0]=prices[i];
                dp[1]=-1;
            } 
            else dp[1]=max(dp[1],prices[i]);
            if(dp[1]>dp[0]) max_value=max(max_value,dp[1]-dp[0]);
        }
        return max_value>0?max_value:0;
    }
};
// @lc code=end

