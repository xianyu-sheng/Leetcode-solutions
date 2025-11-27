/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*
            比较含退格的字符串  直接使用两个双端队列，如果有‘#’那么就从尾部弹出 最后从头部依次弹出然后来比较
            但是这是空间复杂度为O（n）的方案  不太理想 或许我们可以使用这样的方法
            就是我们从s  t的最后一个元素开始遍历 其实无论他是怎么空格的 那么其应该有的字符顺序一定是不变的 如果遇见了#就往前跳 这样绝不会因为说后面有#然后顺序发生变化 不过这里
估计需要注意的是多个#的情况 那么跳的个数应该就是  #_num+1
            这里有几种的情况：
            1.s t目前都不是# 那么直接比较   相等则是继续 不相等返回fasle
            2.s 如果是# 计算#号个数 然后往前跳
              t 如果是#  计算#号个数  然后往前跳 ---->跳到被回退的最后一个字符上  然后开始下一轮  
        */
        int i=s.size()-1;
        int j=t.size()-1;

        while(i>=0 || j>=0){
            int skip_S=0,skip_T=0;
            //在s中寻找下一个有效的字符串  根据#个数开始回退
            while(i>=0){
                if(s[i]=='#'){++skip_S;--i;}
                else if(skip_S>0){--skip_S;--i;}
                else    break;
            }
            while(j>=0){
                if(t[j]=='#'){++skip_T;--j;}
                else if(skip_T>0){--skip_T;--j;}
                else    break;
            }
            //现在都找到了有效字符  或者  将字符看完了 先看看是不是看完了
            if(i<0 && j<0)  return true;
            //给出不匹配的情况
            if(i<0 || j <0 || s[i]!=t[j])   return false;
            //如果两种情况都不满足 那么就继续下一个
            i--;j--;
        }
        return true;
    }
};
// @lc code=end

