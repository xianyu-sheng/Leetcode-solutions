/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        /*
            解题思路：使用栈来模拟，我们只将左括号放入到栈中
            如果匹配上一个就继续
            这里需要记录的是几种异常情况，这些清况下，我们就返回false
            1.如果我目前的s[i]是右括号，但是栈中已经没有左括号进行匹配了，那么就false【右括号多】
            2.如果匹配完了 栈中还有元素 那么就false【左括号多】
            3.还有就是弹出来的不匹配

            但是这样来解决这道题我们会限于写一堆的if-else的判断条件，不如这样，在我们遇到左括号的时候，就将右括号压入栈
            最后，遇到右括号的时候我们就直接来进行匹配，这样可以简化对比的流程，这样如果不匹配直接下课
        */
        if(s.size()%2==1)   return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')   st.push(')');
            else if(s[i]=='[')  st.push(']');
            else if(s[i]=='{')  st.push('}');
            else if(st.empty() || st.top()!=s[i]){
                return false;
                //这里就代表着我说的第一号和第三号清况
            }
            else{
                st.pop();
            }
        }
        return st.empty();//第二号情况
    }
};
// @lc code=end

