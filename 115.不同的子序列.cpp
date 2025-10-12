/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        /*
            题目理解：这个题也应该由动态规划的思想来解决 至于如果有一个dp数组 比如dp[i][j]来记录状态的话 那么我认为其实可以外层是s  内层是t  然后dp[i][j]的含义就是在s的子串0-i中包含了t的子串0-j的个数 并且应该是全包含 也即是s的子串要完全的包含t  并且呢  其实我们可以看到他里面的这个判断子串的逻辑是什么 其实就可以使用力扣的392题的判断子序列来处理  不过外层我们可以看到就是它应该是最长公共子序列的逻辑  所以我认为这个代码应该这样编写
            for(int i=0;i<s.size();i++){
                for(int j=0;j<t.size();j++){
                    string  str1=s的0-i的子串
                    string str2=t的0-j的子串
                    if(调用392题的判断子序列逻辑)//如果返回true{
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1])
                    }
                }
            }
        */
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //初始化第一列  表达如果t是空串的话 也有一种方案
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        //然后开始填写dp数组
        for(int  i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]=dp[i][j+1];
                if(s[i]==t[j]){
                    //那么就有两种选择：第一，使用s[i]  第二 不使用s[i]
                    dp[i+1][j+1]=dp[i][j]+dp[i][j+1];
                }
            }
        }
        return  dp[n][m];
    }
};
// @lc code=end

