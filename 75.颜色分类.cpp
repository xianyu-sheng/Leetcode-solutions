/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            解决思路：这里我在想可以使用这样的方式不 就是使用一个双指针 从前扫描和从后扫描
            如果在后面碰见0了 就放前面去 如果在前面碰见2了 就放到后面去 然后如果是已经处于该有的位置就跳过 
            这样不用管1  因为我觉得他会与0或者2 调换位置 只要0 2 位置合理   那么自然1的位置也合理
            如果比如在前面我们想要找到2与后面的0换  那么前面出现了1  那么就在扫描一段 找到一个2来先与1换 然后在与0换

            但是这样会出现问题 就是我们交换过来的时候  还会进行检查  这样会出现问题 因此这里如果采用三指针会更好
        */
        int left=0,right=nums.size()-1,current=0;
        while(current<=right){
            if(nums[current]==0){
                swap(nums[current++],nums[left++]);
            }else if(nums[current]==2){
                swap(nums[current],nums[right--]);
            }else{
                current++;
            }
        }
    }
};
// @lc code=end

