/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
            解题策略：整个数组就是表示一个整数 然后我们+1的话 就需要判断是否有进位  如果有进位的话 就需要将其向上加1  
            特别是最后一位如果为9的话 那么还需要进1
            先将数组翻转过来，方便最后一位的扩展
            然后在翻转过来
        */
        reverse(digits.begin(),digits.end());
        //然后开始来进行翻转
        int up_num=1;//表示进位
        for(int i=0;i<digits.size();i++){
            //当前位与进位相加 然后除数等于进位 然后余数等于当前位
            int num=digits[i]+up_num;
            digits[i]=num%10;
            up_num=num/10;
        }
        //然后检验up_num是不是大于1
        if(up_num>0)    digits.push_back(up_num);
        reverse(digits.begin(),digits.end());

        return digits;
    }
};
// @lc code=end

