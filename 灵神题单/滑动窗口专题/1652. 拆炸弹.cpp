//方法1：前缀和
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) return vector<int>(n, 0);

        // 策略：将数组扩充为 2*n 长度来模拟循环
        // 这样可以规避取模带来的前缀和索引问题
        vector<int> nums = code;
        nums.insert(nums.end(), code.begin(), code.end()); // 拼接 [1,2,3, 1,2,3]

        // 计算 2n 长度的前缀和
        vector<int> pre_sum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                // 如果 k>0，求后 k 个的和
                // 对应扩充数组下标范围：[i+1, i+k]
                // 前缀和计算：pre_sum[i+k+1] - pre_sum[i+1]
                ans[i] = pre_sum[i + k + 1] - pre_sum[i + 1];
            } else {
                // 如果 k<0，求前 |k| 个的和
                // 此时我们需要利用第二段数组带来的便利
                // 我们可以把当前的 i 映射到第二段的 i (即 i+n)，这样往前找 |k| 个就不会越界
                // 对应下标范围：[(i+n)-|k|, (i+n)-1]
                // 设 K = abs(k)，范围 [i+n-K, i+n-1]
                // 前缀和计算：pre_sum[i+n] - pre_sum[i+n-abs(k)]
                ans[i] = pre_sum[i + n] - pre_sum[i + n + k]; // k是负数，所以直接 +k
            }
        }
        return ans;
    }
};
//空间复杂度为O(1)的滑动窗口版本
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;

        // 初始化窗口和以及左右指针
        int w_sum = 0;
        int l, r; // l是窗口左端，r是窗口右端

        if (k > 0) {
            l = 1;
            r = k;
        } else {
            l = n - abs(k);
            r = n - 1;
        }

        // 计算第一个窗口的初始和
        // 注意：这里需要处理循环，但因为是初始状态，直接累加即可
        // 或者是利用取模来防止越界，但更简单的是把 code 当作 2*n 长看（逻辑上）
        // 这里直接简单累加初始窗口
        for (int i = l; i <= r; i++) {
            w_sum += code[i];
        }
        ans[0] = w_sum;

        // 开始滑动
        for (int i = 1; i < n; i++) {
            // 减去离开窗口的元素
            w_sum -= code[l % n];
            // 加上进入窗口的元素
            w_sum += code[(r + 1) % n];
            
            ans[i] = w_sum;
            
            // 指针移动
            l++;
            r++;
        }

        return ans;
    }
};
