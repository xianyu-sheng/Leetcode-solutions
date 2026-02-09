//我的思路
class Solution {
public:
    // 计算位移的辅助函数：逻辑完全保留你的，修正了返回值访问方式
    pair<int,int> Compute_pos(const string& str){
        int x = 0, y = 0;
        for(size_t i = 0; i < str.size(); i++){
            switch(str[i]) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
            }
        }
        return make_pair(x, y);
    }

    int distinctPoints(string s, int k) {
        set<pair<int,int>> Counts;
        
        // 1. 获取总位移
        pair<int,int> total = Compute_pos(s);
        int X = total.first;
        int Y = total.second;

        // 2. 窗口初始化（先拿到第一个长度为 k 的子串位移）
        string sub_str = s.substr(0, k); 
        pair<int,int> sub_pos = Compute_pos(sub_str);
        
        // 3. 记录删除第一个子串后的终点
        Counts.insert({X - sub_pos.first, Y - sub_pos.second});

        // 4. 局部滑动窗口修改
        // 为了避免在循环内重复调用 Compute_pos (导致 O(N*K) 复杂度)
        // 我们在循环里手动更新 sub_pos 的值
        for(int i = k; i < s.size(); i++) {
            // 移入新字符 s[i]
            if (s[i] == 'U') sub_pos.second++;
            else if (s[i] == 'D') sub_pos.second--;
            else if (s[i] == 'L') sub_pos.first--;
            else if (s[i] == 'R') sub_pos.first++;

            // 移出旧字符 s[i-k]
            char out = s[i - k];
            if (out == 'U') sub_pos.second--;
            else if (out == 'D') sub_pos.second++;
            else if (out == 'L') sub_pos.first++;
            else if (out == 'R') sub_pos.first--; // 关键修正：这里是减法

            // 记录当前移除子串后的结果
            Counts.insert({X - sub_pos.first, Y - sub_pos.second});
        }

        return Counts.size();
    }
};

//灵神第一版
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        unordered_set<long long> st;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            // 1. 入
            switch (s[i]) {
                case 'L': x--; break;
                case 'R': x++; break;
                case 'D': y--; break;
                case 'U': y++; break;
            }

            int left = i + 1 - k; // 窗口左端点
            if (left < 0) { // 窗口大小不足 k
                continue;
            }

            // 2. 记录答案
            // 把两个 int 压缩到一个 long long 中，+n 避免负数
            st.insert(1LL * (x + n) << 32 | (y + n));

            // 3. 出，为下一个窗口做准备
            switch (s[left]) {
                case 'L': x++; break;
                case 'R': x--; break;
                case 'D': y++; break;
                case 'U': y--; break;
            }
        }
        return st.size();
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/distinct-points-reachable-after-substring-removal/solutions/3793905/deng-jie-zhuan-huan-ding-chang-hua-dong-3b67r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
