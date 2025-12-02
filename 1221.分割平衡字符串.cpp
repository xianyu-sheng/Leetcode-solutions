/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        /*
            怎样使用贪心策略来划分平衡字符串  使用L R分别计数  这样如果只要满足了L=R 就立马重新初始化
        */
        int num_L=0;
        int num_R=0;
        int sub_str=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L')   num_L++;
            else    num_R++;
            //如果已经构成子串了 那么就重置并子串个数++
            if(num_L==num_R){
                sub_str++;
                num_L=0;
                num_R=0;
            }
        }
        return sub_str;
    }
};
// @lc code=end

