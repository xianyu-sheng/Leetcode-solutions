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
//动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        //使用动态规划来记性解答
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int max_length=0;
        int left=0;
        int right=0;
        //然后开始推导dp数组  从下往上 从左到右
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                //直接给出如果i j 相等时候的情况
                if(s[i]==s[j]){
                    //如果是j-i <=1 你们说明这是一个长度为2 或者长度为1 的字符串 他必然是回文字符串
                    if(j-i <= 1){
                        dp[i][j]=true;
                    }else if(dp[i+1][j-1]){
                        //如果排除掉两侧的字符，看看中间的字符是不是回文的
                        dp[i][j]=true;
                    }
                }
                //然后来统计这个最长的字符串
                if(dp[i][j] && j-i+1 > max_length){
                    max_length=j-i+1;
                    left=i;
                    right=j;
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};

// @lc code=end

