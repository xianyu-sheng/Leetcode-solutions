class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count_1=0;
        int ans=INT_MAX;
        string ans_str="";
        for(int l=0,r=0;r<s.length();r++){
            //1.如果是'1'  则记录
            count_1+=(s[r]=='1');
            //2.然后来尽可能的缩小
            while(count_1==k){
                //获取当前窗口的字符串和长度
                int current_len=r-l+1;
                string current_str=s.substr(l,current_len);
                //缩小窗口
                if(current_len < ans){
                    ans=current_len;
                    ans_str=current_str;
                }else if(current_len==ans){
                    //长度相同时  则需要比较字典序
                    if(current_str < ans_str){
                        ans_str=current_str;
                    }
                }
                //更新
                count_1-=(s[l]=='1');
                l++;
            }
        }
        return ans_str;
    }
};

//灵神的枚举法
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // 1 的个数不足 k
        if (ranges::count(s, '1') < k) {
            return "";
        }
        // 否则一定有解
        for (int size = k; ; size++) {
            string ans = "";
            for (int i = size; i <= s.length(); i++) {
                string t = s.substr(i - size, size);
                if ((ans.empty() || t < ans) && ranges::count(t, '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
    }
};

//滑动窗口模板
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }
        string ans = s;
        int cnt1 = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            cnt1 += s[right] - '0';
            while (cnt1 > k || s[left] == '0') {
                cnt1 -= s[left++] - '0';
            }
            if (cnt1 == k) {
                string t = s.substr(left, right - left + 1);
                if (t.length() < ans.length() || t.length() == ans.length() && t < ans) {
                    ans = move(t);
                }
            }
        }
        return ans;
    }
};
