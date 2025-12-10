/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            解法：我在想这里可以这样解决不  就是模仿栈的用法 
            就是我使用一个pre来记录我目前记录的数组  然后count来记录他的个数 然后最后输出pre
            如果遇到相同的则pre不变 count++  如果遇到不同的 则count--   pre等count减完再减
        */
        sort(nums.begin(),nums.end());
        int pre=nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==pre){
                count++;
            }
            if(nums[i]!=pre)    count--;
            if(count<=0)    pre=nums[i];
        }
        return pre;
    }
};
// @lc code=end

