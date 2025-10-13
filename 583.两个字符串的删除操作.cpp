/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            题目理解：所谓返回两个单词相同的最小步数  我认为其实可以抽象为其本来就是求他们的最长公共子序列  
            但是怎么来做一个最小步数呢  难道是两个单词分别移向这个公共的序列所需要做的步数吗  我觉得很有可能是 
            所以这样的实现应该就是先按照最长公共子序列的求法 求出最长的公共子序列之后 然后在分别相减
        */
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return (n-dp[n][m])+(m-dp[n][m]);
    }
};
// @lc code=end

