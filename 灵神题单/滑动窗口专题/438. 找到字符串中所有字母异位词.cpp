class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        vector<int> ans;
        if(n<m) return ans;
        //然后先统计第一个窗口
        int num[26]{};
        for(int i=0;i<m;i++){
            num[p[i]-'a']--;
            num[s[i]-'a']++;
        }
        //然后统计不同的地方
        int diff=0;
        for(int x:num)  if(x!=0)    diff++;
        if(diff==0) ans.push_back(0);
        //开始遍历
        for(int i=m;i<n;i++){
            int x=s[i]-'a';
            int y=s[i-m]-'a';
            if(x==y){
                if(diff==0) ans.push_back(i-m+1);
                continue;
            }
            //然后判定不相等的情况
            if(num[x]==0)   diff++;
            num[x]++;
            if(num[x]==0)   diff--;

            if(num[y]==0)   diff++;
            num[y]--;
            if(num[y]==0)   diff--;
            if(diff==0) ans.push_back(i-m+1);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 统计 p 的每种字母的出现次数
        array<int, 26> cnt_p{}; 
        for (char c : p) {
            cnt_p[c - 'a']++;
        }

        vector<int> ans;
        array<int, 26> cnt_s{}; // 统计 s 的长为 p.size() 的子串 t 的每种字母的出现次数
        for (int right = 0; right < s.size(); right++) {
            cnt_s[s[right] - 'a']++; // 右端点字母进入窗口
            int left = right - p.size() + 1;
            if (left < 0) { // 窗口长度不足 p.size()
                continue;
            }
            if (cnt_s == cnt_p) { // t 和 p 的每种字母的出现次数都相同
                ans.push_back(left); // t 左端点下标加入答案
            }
            cnt_s[s[left] - 'a']--; // 左端点字母离开窗口
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/2969498/liang-chong-fang-fa-ding-chang-hua-chuan-14pd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 统计 p 的每种字母的出现次数
        int cnt[26]{}; 
        for (char c : p) {
            cnt[c - 'a']++;
        }

        vector<int> ans;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            int c = s[right] - 'a';
            cnt[c]--; // 右端点字母进入窗口
            while (cnt[c] < 0) { // 字母 c 太多了
                cnt[s[left] - 'a']++; // 左端点字母离开窗口
                left++; 
            }
            if (right - left + 1 == p.size()) { // t 和 p 的每种字母的出现次数都相同（证明见上）
                ans.push_back(left); // t 左端点下标加入答案
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/2969498/liang-chong-fang-fa-ding-chang-hua-chuan-14pd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
