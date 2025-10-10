/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            题目理解：具有最大和的连续子数组  那说明这里就需要加一个判定目前是否是连续的  如果不是连续的应该直接置于0 是连续的 那么才继续进行状态的更新
            那么就应该是 用一个一维的dp数组 然后不断记录当前的子数组和    也就是说dp[i]代表着当前子数组的和 但不是从0->i-1的子数组和
            但我认为这好像不太对  我感觉这样好像是贪心算法的思路
        */
        vector<int> dp(nums.size(),0);
        int max_result=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]); // 核心 DP 转移
            max_result = max(max_result, dp[i]);
        }
        return max_result;
    }
};
// @lc code=end

