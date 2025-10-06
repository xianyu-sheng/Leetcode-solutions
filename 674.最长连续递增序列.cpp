/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
//贪心思路
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //这里要连续的 那么指定一个result来记录最长的连续子串 并不停的更新
        int result=1;
        int length=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                length+=1;
                result=max(result,length);
            }
            else{
                length=1;
            }
        }
        return result;
    }
};
//动态规划思路
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //这里如何使用动态规划的思想来解决这个问题呢？
        //定义一个dp数组：每一个元素其实自己本身就是一个最小的递增子序列  然后如果当前元素比前一个要大 那么就根据前一个状态更新当前状态
        int rel=1;
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
            }
            rel=max(rel,dp[i]);
        }
        return rel;
    }
};
// @lc code=end

