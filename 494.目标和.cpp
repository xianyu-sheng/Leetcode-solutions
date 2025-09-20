/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int  backtracking(vector<int>& nums, int target,int startindex,int sum){
        if(startindex==nums.size()){
            return sum==target?1:0;
        }
        int count=0;
        count+=backtracking(nums,target,startindex+1,sum-nums[startindex]);
        count+=backtracking(nums,target,startindex+1,sum+nums[startindex]);

        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(nums,target,0,0);
    }
};
// @lc code=end

