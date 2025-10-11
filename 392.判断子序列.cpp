/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
//解法1：双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // 指向 s 的指针
        int j = 0; // 指向 t 的指针
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; // 匹配成功，s 的指针前移
            }
            j++; // t 的指针总是前移
        }
        
        return i == s.size(); // 如果 s 的所有字符都匹配完了，就是子序列
    }
};
//解法2：动态规划
class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
            题意理解：这不就是最长公共子序列吗？
            只是这里最后需要判断一下就是这个最长的公共子串长度是不是等于s的长度就行
            
        */
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n][m]==n;
    }
};
// @lc code=end

