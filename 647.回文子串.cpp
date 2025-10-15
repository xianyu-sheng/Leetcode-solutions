/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int  computer(string& s,int i,int j,int n){
        int res=0;
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
            res++;
        }
        return res;
    }
    int countSubstrings(string s) {
        /*
            题目理解：这个题要通过动态规划来解决 那么就需要了解这个题如何使用动态规划？
            比如如何定义dp数组呢？  难道是定义为一个以为dp数组吗？然后dp[i]代表着字符串s的0-i该子字符串中，应该有多少的回文子串
            这里在定义dp数组初始化时候，应该是每一个数组位置都应该初始化为1  因为其本身就是一个回文子串
            但是这里如何去进行状态转移呢
            如果单纯的一维dp数组我感觉还是够呛  或许应该是使用二维dp数组
            然后这样


            这里我感觉动态规划的思路不太好理解 使用双指针法更好理解些
            这里使用双指针法 其实也就是中心扩散法 将s中的每一个字符作为中心进行扩散 计算他们分别的回文字串数量
        */
        int  result=0;
        for(int i=0;i<s.size();i++){
            //以一个奇数作为扩展
            result+=computer(s,i,i,s.size());
            //以偶数扩展
            result+=computer(s,i,i+1,s.size());
        }
        return result;
    }
};
// @lc code=end

