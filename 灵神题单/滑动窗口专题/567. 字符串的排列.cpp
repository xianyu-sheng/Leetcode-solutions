//基础版本实现
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //什么是排列？对s1字符串的每个字符的任意顺序是否能够出现在s2中，如果出现那么就是包含 如果没有那就是不包含
        //以s1字符串的长度为窗口 在s2中滑动
        //使用哈希表来解决这个题+如果窗口内的每个哈希的值与s1相同则说明是true
        if(s1.size()>s2.size()) return false;
        int w=s1.size();
        vector<int> s1_num(26,0);
        vector<int> w_num(26,0);
        //先计算s1的哈希
        for(char x:s1)  s1_num[x-'a']+=1;
        //然后开始遍历
        for(int i=0;i<s2.size();i++){
            w_num[s2[i]-'a']+=1;
            if(i-w+1<0) continue;
            if(w_num==s1_num)   return true;
            w_num[s2[i-w+1]-'a']-=1;
        }
        return false;
    }
};
//时间复杂度优化方法 使用diff来维护变数
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        // cnt[i] > 0 表示 s2 窗口里多了，cnt[i] < 0 表示 s2 窗口里少了
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }

        // 初始窗口的 diff 计算
        int diff = 0;
        for (int x : cnt) {
            if (x != 0) diff++;
        }

        if (diff == 0) return true;

        // 开始滑动
        for (int i = n; i < m; ++i) {
            int x = s2[i] - 'a';           // 右边进来的字符
            int y = s2[i - n] - 'a';    // 左边离开的字符

            if (x == y) { // 进出是同一个字符，diff 不变
                if (diff == 0) return true;
                continue;
            }

            // 更新进来的字符对 diff 的影响
            if (cnt[x] == 0) diff++;       // 原本是平衡的，现在不平衡了
            cnt[x]++;
            if (cnt[x] == 0) diff--;       // 原本不平衡，现在刚好抵消

            // 更新离开的字符对 diff 的影响
            if (cnt[y] == 0) diff++;       // 原本是平衡的，现在变少了
            cnt[y]--;
            if (cnt[y] == 0) diff--;       // 原本不平衡，现在刚好抵消

            if (diff == 0) return true;
        }

        return false;
    }
};
