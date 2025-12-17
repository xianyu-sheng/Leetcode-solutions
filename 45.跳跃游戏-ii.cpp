/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            解题思路：这个跳跃游戏这里每一步可以达到的最远的跳跃路径 然后这里要求求最小的跳跃数 那么
            我们就需要每次尽可能的跳多一点？怎样来设计呢？如果我跳到中间发现有比我现在能够达到的更远的目的地的我就更新吗？
            不是，如果是这样的话，那我们中间岂不是每次遇到一个更大的就会去更新吗？这样的话，是不准确的，我认为，我们走的每一步
            还没有发挥出最大价值的时候，我们就急于跳出下一步，并且当你在原地想要更新的时候，他们的比较也不是对等的
            因此我们应该第一，把每一步发挥出的价值发挥到极致，不走完不罢休
            第二，为了防止频繁的更新，我门应该只是维护一个最远边界，代表当前的最优决策
        */
        if(nums.size()==1)  return 0;

        int steps=0;
        int curend=0;
        int maxpos=0;
        for(int i=0;i<nums.size()-1;i++){
            maxpos=max(maxpos,i+nums[i]);
            if(i==curend){
                curend=maxpos;
                steps++;
            }
        }
        return steps;
    }
};
// @lc code=end

