/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
            使用二分查找法，最后如果没有找到元素，那么就与nums[mid]相比较如果大，则往后排，小则排当下
        */
        int n=nums.size();
        int l=0,r=n-1;
        int mid;
        while(l<=r){
           mid=l+(r-l)/2;
           if(nums[mid]<target) l=mid+1;
           else if(nums[mid]>target)    r=mid-1;
           else return mid;
        }
        //现在就是没有找到的情况
        if(target>nums[mid])  return mid+1;
        else    return l;
    }
};
// @lc code=end

