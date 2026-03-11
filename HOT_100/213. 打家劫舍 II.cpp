class Solution {
    // 198. 打家劫舍
    // 偷下标在 [start, end) 中的房子
    int rob1(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
    }
};
