/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        /*
            解题思路：这里可以怎么解？就是指的是使两个字符串如果要相等话 
            他们应该怎样来删除元素，进一步抽象的话就是说这里在讲两个字符串的
            最长公共子串  然后找出最长公共子串，然后将这个删除掉
            同时注意这里的最长公共子串是逻辑顺序一致，但是肯定是可以不连续的
            第一步，先求出最长的公共子序列
            第二步，再去相减

            但是这样分开做，可能不够高效，那么我们在编写一个基础版的基础上，我们就可以继续的将
            计算需要删除的ASCII值的和的操作，放在匹配最长子串时来进行操作
        */
        int n = s1.size(), m = s2.size();
        // dp[i][j] 表示 s1[0..i-1] 与 s2[0..j-1] 的最小删除和
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // 边界：其中一个串为空
        for (int i = 1; i <= n; ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= m; ++j) dp[0][j] = dp[0][j - 1] + s2[j - 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])   // 字符相等，都不删
                    dp[i][j] = dp[i - 1][j - 1];
                else                          // 删左边 or 删右边，取小者
                    dp[i][j] = min(s1[i - 1] + dp[i - 1][j],
                                   s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

