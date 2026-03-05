//基础做法：将rand7()两次生成的随机数组 看做是7进制数的两位 互不干扰 只需要求满足1-10内的数据就行
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int ans=(rand7()-1)*7+(rand7()-1);//进制转换
            if(ans>=1 && ans<=10)   return ans;
        }
    }
};
//减少rand7()的调用次数
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int ans=(rand7()-1)*7+(rand7()-1);//进制转换
            if(ans>=1 && ans<=40)   return ans%10+1;
        }
    }
};
