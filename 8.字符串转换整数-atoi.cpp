/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        /*
            题目理解：如果是空格那么就跳过，如何检查字符，如果在字符串开头读取到符号了 那么就设置符号，也就是必须在我们的res结果值等于0时读到符号才有用  否则在字符串的中间 不管什么地方遇到不是数字的字符 都立刻停止
        */
        /*
            程序编写方法：将一个个条件抽离开来  分别编写逻辑 这样编写的代码逻辑清晰
            https://lxblog.com/qianwen/share?shareId=89bdc440-e43e-48af-bb6e-8676eb089ff2
        */
        long long res=0;
        int sign=1;
        int i=0;
        //1.跳过前置的空格
        while(i<s.size() && s[i]==' ')  i++;
        //2.处理符号
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        //3.读取数字
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            res=res*10+(s[i]-'0');
            i++;
            // 提前检查是否越界（避免 long long 溢出）
            if (res > INT_MAX) break;
        }
        //4.应用符号
        res*=sign;
        //检查是否越界
        if(res>INT_MAX) res=INT_MAX;
        else if(res<INT_MIN)    res=INT_MIN;

        return res;
    }
};
// @lc code=end

