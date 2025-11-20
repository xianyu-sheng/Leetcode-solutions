/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            解题思路：第一，不复制数组
            第二，我们需要将所有的0移动的数组的末尾，同时保持其他的非0元素的顺序，可以怎么做呢？  我可以这样不？  如果当前的元素，检测到是0 了 那么我们就与下一个元素进行换位  一直往下换 但是我们还需要解决的是，如果连续两个两个值都是0怎么办?  我们必须想一个聪明的策略我认为--> 使用快慢指针，左边是慢指针，来指向0元素，右边呢则不断的去寻找第一个非0元素，然后换了 慢指针在继续+1移动
            这里重点的是怎样避免数组访问越界，怎样将里面的情况理清楚？
            1.如果都为0   fast++
            2.如果都不为0  那么一起++
            3.如果slow==0  fast  不为0   那么就交换
            这里不考虑slow不等于0  而fast为0的情况这里已经包含了
        */
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=0){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
    }
};
// @lc code=end

