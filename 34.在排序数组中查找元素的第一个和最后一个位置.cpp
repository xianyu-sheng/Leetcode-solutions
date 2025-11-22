/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
            题目理解：非递减顺序----> 那么代表的就是其后面的元素要不就是与前一个元素相等，要不就是大于前面的元素
            怎样为log n  那不就是2^x=n  必须要x次数内就完成这个操作吗？
            那么按照这个题意来看这就是一个山峰类型的数组，保证下一个元素是不下去的
            方法1：双指针来解决，不过此时为O（N）
            二分查找 先找到这个target  然后两边看一看就行了
        */
        int  n=nums.size();
        vector<int> rel{-1,-1};
        if(n==0)    return rel;
        int start_index=0;
        int end_index=n-1;
        int mid=-1;
        while(start_index <= end_index){
            mid=start_index+(end_index-start_index)/2;
            if(nums[mid]==target){
                break;
            }
            else if(nums[mid]<target){
                start_index=mid+1;
            }
            else{
                end_index=mid-1;
            }
        }
        if(mid==-1  || nums[mid]!=target)   return  rel;
        //然后开始探寻
        int left=mid,right=mid;
        while(left >0 && nums[left-1]==target)  --left;
        while(right<n-1 && nums[right+1]==target)   ++right;
        return {left,right};
    }
};
// @lc code=end

