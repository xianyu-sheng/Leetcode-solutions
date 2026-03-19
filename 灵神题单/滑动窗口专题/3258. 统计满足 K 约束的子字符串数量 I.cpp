class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count_0=0,count_1=0;
        int ans=0;
        for(int l=0,r=0;r<s.length();r++){
            count_0+=('1'-s[r]);//计算'0'
            count_1+=(s[r]-'0');//计算'1'

            //然后现在来统计如果满足
            while(count_0>k && count_1>k){
                count_0-=('1'-s[l]);
                count_1-=(s[l]-'0');
                l++;
            }
            //然后统计
            ans+=(r-l+1);
        }
        return ans;
    }
};

//灵神
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0, left = 0, cnt[2]{};
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[left] & 1]--;
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};
