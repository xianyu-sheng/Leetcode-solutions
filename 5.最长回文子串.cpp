/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    void  IsPalindrome(string& s,int& left,int& right){
        int  n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        left++;
        right--;
    }
    string longestPalindrome(string s) {
        //中心扩展法---->解决思路 O(n^2)的算法复杂度
        if(s.empty())   return "";
        int  best_left=0;
        int best_right=0;
        int n=s.size();

        //遍历每一个可能的“中心点”
        for(int i=0;i<n;i++){
            //1.回文子串是一个奇数长度，中心是一个字符
            int l_1=i,r_1=i;
            IsPalindrome(s,l_1,r_1);

            //2.回文子串是偶数长度，中心是两个字符
            int l_2=i,r_2=i+1;
            if(r_2 < n){
                IsPalindrome(s,l_2,r_2);
            }

            if(r_1-l_1 > best_right-best_left){
                best_left=l_1;
                best_right=r_1;
            }
            if(r_2-l_2 > best_right-best_left){
                best_left=l_2;
                best_right=r_2;
            }
        }
        return  s.substr(best_left,best_right-best_left+1);
    }
};
// @lc code=end

