/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            题意理解：本题编辑距离的意思，我认为其实也还是先求出最长的公共子序列  然后在加以判断  比如当word1.size()>word2.size()时：
                （1）如果最长公共子序列等于word2.size()  那么直接word1.size()-该序列长度
                (2)如果最长公共子序列小于word2.size()  说明需要先将word1的字符串 删除到与word2一样  然后在进行替换
            当word1.size()<word2.size()时：
                （1）最长公共子序列等于word1.size()的长度，那么直接添加word2.size()-word1.size()的长度即可
                （2）如果最长长公共子序列小于word1,size()的长度，那么先替换word1.size()-最长公共子序列的长度 然后插入word2.size()-word1.size()的长度

                发现行不通 我发现这里他的删除和替换操作是根顺序相关的 即如果是
        */
        int  n=word1.size();
        int  m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //将word1转换成空串需要多少步
        for (int i = 0; i <= n; i++)
                dp[i][0] = i;
        //在word1=""时将其转换为word2需要多少步
        for (int j = 0; j <= m; j++)
                dp[0][j] = j;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j];//如果当前的字符相等 那么就什么都不做
                }
                else{
                    //如果不等于 则有三种操作 要么删除 插入 替换  选择里面操作数最小的
                    dp[i+1][j+1]=min(dp[i][j+1]+1,min(dp[i+1][j]+1,dp[i][j]+1));
                }
            }
        }
        return  dp[n][m];
    }
};
// @lc code=end

