class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // 空字符串可以被拆分
        //这个题本质上是求排列数 因此需要外层便利背包  内层遍历物品 要求有顺序
        for (int i = 1; i <= n; ++i) {
            for (const string& word : wordDict) {
                int len = word.size();
                if (i >= len && dp[i - len] && s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};