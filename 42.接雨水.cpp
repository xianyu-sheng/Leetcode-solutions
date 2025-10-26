/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        /*
            解题思路：这道题可以使用双指针来解决 首先，就是左指针必须大于0然后才能开始算 并且一定要封闭的才行 至于怎样封闭呢 并且每一个封闭区间内有间隙  可以按照下面的规则来计算
            情况1：左指针小于等于右指针  且中间有间隙
                右指针高度-左指针高度-中间空隙
            情况2：右指针<左指针 且中间有间隙 （也就是right-left>1）
                左指针高度-右指针高度-中间空隙的体积
        伪代码：
            定义左右指针
            左指针先移到数组height中第一个不为0的位置，然后将left->right
            然后就是right移动  直到找到第一个大于等于left并且  right-left大于1的位置  然后记录体积  left=right
                                （或者是小于的）
            然后不停的移动
        */
        //使用全局双指针才得行，虽然都是去算凹槽
        if(height.empty())  return 0;
        int left=0,right=height.size()-1;
        int left_max=0,right_max=0;
        int vol=0;
        while(left<right){
            left_max=max(left_max,height[left]);
            right_max=max(right_max,height[right]);
            if(height[left]<height[right]){
                vol+=min(left_max,right_max)-height[left];
                left++;
            }
            else{
                vol+=min(left_max,right_max)-height[right];
                right--;
            }
        }
        return vol;
    }
};
// @lc code=end

