class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        //半重复子字符串：至多有一对相邻字符是想等的 那么我们需要使用一个变量来维护这个窗口内的相等字符的 如果超过了则需要移动 怎么移动 通过left指向以及 Left+1指向来进行移动
        int ans=1;
        int count_equl=0;
        for(int l=0,r=1;r<s.length();r++){
            if(s[r]==s[r-1])    count_equl++;
            //然后此时再来检查是不是大于了1
            while(count_equl>1){
                //那么就应该进行调整
                if(s[l]==s[l+1])    count_equl--;
                l++;//但是左侧的窗口是无条件的需要移动的
            }
            //更新最长的参数
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

//灵神解题
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, same = 0, left = 0;
        for (int right = 1; right < s.length(); right++) {
            if (s[right] == s[right - 1]) {
                same++;
            }
            if (same > 1) { // same == 2
                left++;
                while (s[left] != s[left - 1]) {
                    left++;
                }
                same = 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
