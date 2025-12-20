/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        /*
            对于这一个题，咋一看可能感觉迷糊，但是我们剖析一下
            发现这道题就是说如果我出现了k[]这样的组合，那么[]里面的字符串
            重复k次  然后有这样的输入我们才进行这样的组合，如果没有就不加
            这里我们可以采用一个栈来维持[]的下标，方便给出索引进行子串的分割

            但是这里我门在编码上，就不能只是简单的认为下一个出现的不是字母的字符就是]  因为这里还有嵌套的
            情况 那么这里我们需要维护两个栈，一个栈维护我们遇到[前的已经构造好的字符串，同时维护这个[]前的数字在一个k_st中
        */
        stack<int> nums_st;
        stack<string> strs_st;

        string current_str="";//记录当前正在处理的字符串
        int current_num=0;//记录当前计算的倍数

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c>='0' && c<='9'){
                //如果是数字我们就可以通过这个来处理多位数的情况
                current_num=current_num*10+(c-'0');
            }else if(c=='['){
                //遇到了左括号，那么我就需要将倍数以及当前已经构造的字符串加入到栈
                nums_st.push(current_num);
                strs_st.push(current_str);
                //然后置为初始状态
                current_num=0;
                current_str="";
            }else if(c==']'){
                //那么就是需要将当前的current_str*current_num+pre_str
                int k=nums_st.top();nums_st.pop();
                string pre_str=strs_st.top();strs_st.pop();
                //然后乘以倍数
                for(int j=0;j<k;j++){
                    pre_str+=current_str;
                }
                //更新current_str
                current_str=pre_str;
            }else{
                //否则就是普通字符 直接加入
                current_str+=c;
            }
        }
        return current_str;
    }
};
// @lc code=end

