class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size(), m = nums2.size();

        const long long INF = 1e18;
        long long f[n + 1][m + 1][K + 1];
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= K; k++) f[i][j][k] = -INF;
        f[0][0][0] = 0;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= K; k++) {
            // 跳过 nums1 的下一个元素
            if (i > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
            // 跳过 nums2 的下一个元素
            if (j > 0) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k]);
            // 把 nums1 和 nums2 的下一个元素组成一对
            if (i > 0 && j > 0 && k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1] + 1LL * nums1[i - 1] * nums2[j - 1]);
        }
        return f[n][m][K];
    }
};
