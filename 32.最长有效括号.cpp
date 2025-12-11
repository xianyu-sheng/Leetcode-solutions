/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        /*
            解题思路：这里纪要判断这个括号是否是有效的  同时还要求最长的括号子串
            这就要求从不同的位置划分这个子串 然后来看是否可行 最主要的是需要覆盖这么多种可能
            然后我的想法是设计一个dp数组  所有位置都初始化为false
            然后每次都将这个i  ~ j的子串 给一个函数来检查 这个函数就是送入一个栈来检查 
            并且每次返回true的时候更新这个最长的子串

            不过我感觉这样会超时

            第一个方法：栈解法
            第二个方法：动态规划解法
        */
        stack<int> st;
        st.push(-1);
        int max_len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')   st.push(i);//存下标
            else{
                //尝试匹配
                st.pop();
                if(st.empty()){
                    //匹配失败
                    st.push(i);
                }
                else{
                    max_len=max(max_len,i-st.top());
                }
            }
        }
        return max_len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        /*
            解题思路：这里纪要判断这个括号是否是有效的  同时还要求最长的括号子串
            这就要求从不同的位置划分这个子串 然后来看是否可行 最主要的是需要覆盖这么多种可能
            然后我的想法是设计一个dp数组  所有位置都初始化为false
            然后每次都将这个i  ~ j的子串 给一个函数来检查 这个函数就是送入一个栈来检查 
            并且每次返回true的时候更新这个最长的子串

            不过我感觉这样会超时

            第一个方法：栈解法
            第二个方法：动态规划解法
        */
        int n=s.size();
        if(n==0) return 0;
        vector<int> dp(n,0);
        int max_len=0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')   dp[i]=0;
            else{
                //情况A ：s[i-1]=='('
                if(s[i-1]=='('){
                    dp[i]=(i>=2 ? dp[i-2]:0)+2;
                }
                else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i - 1] + 2 + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0);
                }
                max_len=max(dp[i],max_len);
            }
        }
        return max_len;
    }
};
// @lc code=end

