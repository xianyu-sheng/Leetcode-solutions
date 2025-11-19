/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    int compute(int j,int i,vector<int>& nums){
        //如果是左侧
        int rel=0;
        if(j<i){
            while(j>=0){
                if(nums[j]<nums[i]){
                    rel++;
                }
                j--;
            }
        }
        else if(j>i){
            while(j<nums.size()){
                if(nums[j]<nums[i]){
                    rel++;
                }
                j++;
            }
        }
        return rel;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        /*
            解题思路：第一，这里不能使用排序，否则这里的位置就乱了，返回的结果数组就不能够对应的
            第二，但是如何高效的能够找出小于自己的数字的数目呢？
            使用一个函数把？  判断如果小于但道个歉元素的下标  那么就--  如果大于元素的下标 就++
        */
        //然后开始来遍历
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int num=0;
            if(i==0){
                num+=compute(i+1,i,nums);
                result.push_back(num);
            }
            else{
                num+=compute(i+1,i,nums);
                num+=compute(i-1,i,nums);
                result.push_back(num);
            }
        }
        return result;
    }
};
// @lc code=end

