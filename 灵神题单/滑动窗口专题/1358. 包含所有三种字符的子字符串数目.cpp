class Solution {
public:
    int numberOfSubstrings(string s) {
        /*
            包含所有三种字符的子字符串数目：这里一定是要包含3种字符的  一次以上的出现次数 
            然后这里在检查窗口内的字符是否都满足的时候 必须有四点条件
            1.a b c是不是满足条件 
            2.子字符串的个数至少为3
        */
        int cnt[3]={};//用来做哈希数组
        int ans=0;
        for(int l=0,r=0;r<s.length();r++){
            cnt[s[r]-'a']++;

            //然后这里我们来检查 是否是够的
            while(cnt[0]>=1 && cnt[1]>=1 && cnt[2]>=1 && (r-l+1)>=3){
                //这里移开需要移除
                cnt[s[l]-'a']--;
                l++;
            }
            //最后退出了 肯定是不满足某一项条件的 那么之前的肯定就是满足的
            ans+=l;
        }
        return ans;
    }
};
