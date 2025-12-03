/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        /*
            解题思路：这个题我咋一看感觉是需要贪心来做的 我们在每次分割回文串的时候都尽可能的多分
            然后返回最少的分割次数

            不过这里我看评论区里面的可以使用那个叫什么动态规划+中心扩散法来解决 不过我该如何的来进行解决呢  怎样能够判断是最少的次数的呢？
            动态规划五部曲：
            1.定义：dp[i]代表字符串0~i-1需要的最少分割数
            2.初始化：在没有任何切割时，每两个字符之间就需要切一刀  所以dp[i]=i
            3.状态转移方程：
            对于每个回文中心，我们向左右扩展，一旦发现 s[i..j] 是回文，就说明：
            可以把 [i..j] 整段当作最后一段，那么前面的 s[0..i-1] 的最少刀数 + 1 就是候选值。
            如果 i==0，说明整段就是 s[0..j]，本身就是回文，刀数 = 0。
            用代码一句话表示：
            dp[j] = min(dp[j], (i==0 ? -1 : dp[i-1]) + 1)
        */
        if(s.size()<=1) return 0;
        //1.定义一个动态数组
        vector<int> dp(s.size(),0);
        //2.初始化
        for(int i=0;i<s.size();i++) dp[i]=i;
        //然后来开始进行推导
        for(int i=0;i<s.size();i++){
            expand(i,i,s,dp);
            expand(i,i+1,s,dp);
        }
        return dp[s.size()-1];
    }
    //定义一个中心扩展的函授
    void expand(int i,int j,const string& s,vector<int>& dp){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            dp[j]=min(dp[j],(i ==0 ?-1:dp[i-1])+1);
            i--;
            j++;
        }
    }
};
// @lc code=end

