class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long K) {
        int n = nums.size();

        long long ans = 0;
        // dq1：队头记录滑动窗口内最大值的下标
        // dq2：队头记录滑动窗口内最小值的下标
        deque<int> dq1, dq2;
        // 枚举子数组右端点 i，看代价不超过 k 的子数组左端点 j 最左可以到哪里
        for (int i = 0, j = 0; i < n; i++) {
            // 新元素加入单调队列
            while (!dq1.empty() && nums[dq1.back()] <= nums[i]) dq1.pop_back();
            dq1.push_back(i);
            while (!dq2.empty() && nums[dq2.back()] >= nums[i]) dq2.pop_back();
            dq2.push_back(i);

            while (j < i && 1LL * (nums[dq1[0]] - nums[dq2[0]]) * (i - j + 1) > K) {
                j++;
                // 将范围外的元素从单调队列移除
                if (dq1[0] < j) dq1.pop_front();
                if (dq2[0] < j) dq2.pop_front();
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
解析链接：https://gemini.google.com/share/43e32bc67102
