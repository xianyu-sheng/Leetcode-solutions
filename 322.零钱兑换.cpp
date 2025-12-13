/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            零钱兑换：我们要最少硬币数 那么就这样也是一种排列组合的结果    然后我们还是需要外围是背包 内围是coins
            然后还是需要使用动态规划：
            1.确定dp数组下标以及含义：   dp[i]代表当前的金额可以使用最少的coins数来组成  然后这里我们默认为初始化为-1 不能够被零钱兑换
            2.确定递推公式：dp[i]=min(dp[i],dp[i-coin]+1)
            3.初始化：INT_MAX  dp[0]=0
            4.遍历顺序应该是外围是背包  内卫是coins
        */
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(auto& coin : coins){
                if(i >= coin && dp[i-coin]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==INT_MAX ? -1:dp[amount];
    }
};
// @lc code=end

