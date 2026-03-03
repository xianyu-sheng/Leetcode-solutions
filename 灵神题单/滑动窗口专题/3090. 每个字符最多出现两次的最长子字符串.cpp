class Solution {
public:
    int maximumLengthSubstring(string s) {
        //最多出现两次 那么如果出现了大于两次就说明该移动子串的左端点了  然后仅有小写英文字母 那么就可以使用数组充当哈希表
        int cnt[26]={};
        int ans=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            //加入到cnt
            cnt[s[right]-'a']++;
            while(cnt[s[right]-'a']>2){
                //如果大于2 那么就移动更新
                cnt[s[left]-'a']--;
                left++;
            }
            //更新
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
