/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
//方法1 直观的哈希表理解
	class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> count; // 哈希表统计次数
        for (int num : nums) {
            if (++count[num] > 1) { // 只要出现2次，就是目标元素
                return num;
            }
        }
        return -1; // 题目保证有解，不会执行到这里
    }
};

	//方法2  利用鸽笼的数学原理
	class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 检查相邻元素
            if (i+1 < n && nums[i] == nums[i+1]) {
                return nums[i];
            }
            // 检查间隔1位的元素
            if (i+2 < n && nums[i] == nums[i+2]) {
                return nums[i];
            }
        }
        // 特殊情况：N=2且目标元素在首尾（如[1,2,3,1]），直接返回最后一个元素
        return nums.back();
    }
};
// @lc code=end

