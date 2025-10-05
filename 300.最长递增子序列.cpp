/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            这样来判断最长的子序列呢？这里的最长如何来判断，怎样解决呢？
            我用一个只有两个空间的数组来进行搭建，前面的是前一个数值  后一个位置是当前最长的子序列长度

            如果当前数值比前一个数值更小，那么就更新第一位是当前数值的大小，第二位就等于前面的最大长度
        */
        if(nums.size()<=1)  return  nums.size();
        vector<int> dp(nums.size(),1);
        int result=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>result)    result=dp[i];
        }
        return result;
    }
};
// @lc code=end

