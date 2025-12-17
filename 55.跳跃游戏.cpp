/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        /* 
            判断能不能达到最后一个位置 就是看我们最后的维护的最远边界是否等于这个nums.size()-1
        */
        if(nums.size()==1)  return true;
        int cuernd=0;
        int maxpos=0;
        for(int i=0;i<nums.size()-1;i++){
            maxpos=max(maxpos,i+nums[i]);
            if(i==cuernd){
                cuernd=maxpos;
            }
        }
        return cuernd>=nums.size()-1;
    }
};
// @lc code=end

