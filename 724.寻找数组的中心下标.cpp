/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
            解题思路：使用左右指针 分别计算左右区间的值  然后只要一有相等就返回
            并且左右差值必须最低为1 如果单纯的使用左右的阈值来进行解答的话 那么会很容易陷入
            条件的梳理  我们完全可以这种思路 我们先统计综合 然后来根据综合来计算leftNum  rightnum就是总和相减
        */
        int sum=0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        int left_num=0;
        int right_num=0;
        for(int i=0;i<nums.size();i++){
            left_num+=nums[i];
            right_num=sum-left_num+nums[i];
            if(left_num==right_num) return i;
        }
        return -1;
    }
};
// @lc code=end

