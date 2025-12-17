/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            解题思路：这个题的解决思路其实可以抽象为这样的就是我们这里只能够维持一次买卖股票的
            时机，那么我们就进行来不断的遍历 最后统计  但是这里需要注意的是什么呢？如果卖股票
            的最大值出现在了买股票的之前怎么解决？比如这里的[7,1,5,3,6,4] 感觉这里还是需要继续
            思考  但是这里我可不可以这样呢？就是使用一个双指针，因为我们的买股票其实就是肯定在卖股票
            之前的
        */
        int minPrice=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minPrice){
                minPrice=prices[i];
            }else if(prices[i] - minPrice > maxprofit){
                maxprofit=prices[i]-minPrice;//这里之所以可以直接更新，就是隐式的采用了我上面的双指针的解法，因为最小值只有一个
            }
        }
        return maxprofit;
    }
};
// @lc code=end

