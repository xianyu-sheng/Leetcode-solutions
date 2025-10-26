/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            解题思路：什么思路呢？这个题如果按照比较笨拙的阶梯办法就是，先进行排序，如果数组中的每一个数值都是紧挨着的 那么缺失的第一个正数就在两侧找 比如最小值大于1  那么缺失的第一个正数就是1  如果从一一直连续  那么第一个正数就是max_item+1
            在代码中，当我们遍历数组的时候我认为只需要维护两个值就行 即看连续的两个数组值之间有没有断开 如果断开了 那么就从Item[i-1]+1处就是需要返回的值
        */
        int  n=nums.size();
        for(int  i=0;i<n;i++){
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
// @lc code=end

