class Solution {
public:
    bool queryString(string s, int n) {
        /*
            这里可以这样做：
            统计如果将n转换为二进制需要几位数，然后就设置1-bit_n的窗口长度来遍历
            设计一个cnt哈希表来记录每个数字是不是能够被正确的表示
        */
        // 剪枝：如果 n 很大，直接返回 false (LeetCode测试用例特性)
        if (n > 2000) return false;

        // 1. 获取二进制宽度 (强制转为 unsigned int 解决编译报错)
        int width_n = std::bit_width((unsigned int)n);
        
        // 2. 初始化标记数组 (使用 vector 替代变长数组)
        // 初始化为 1，表示"还需要找到 1 次"
        vector<int> cnt(n + 1, 1);

        // 3. 遍历窗口长度
        // 【修正点】从 i=1 开始，否则无法检测数字 1
        for (int i = 1; i <= width_n; i++) {
            
            // 遍历字符串 s 的每一个结束位置 j
            for (int j = 0; j < s.size(); j++) {
                
                // 计算窗口左边界
                int left = j - i + 1;
                
                // 【关键修正】防止数组越界！
                // 只有当窗口左边在字符串内时，才进行截取
                if (left < 0) continue;

                // 截取子串
                string sub = s.substr(left, i);
                
                // 转为数字
                try {
                    // 使用 stoi 将二进制字符串转为十进制
                    int dic = std::stoi(sub, nullptr, 2);
                    
                    // 如果转换出的数字在 [1, n] 范围内，标记为已找到
                    if (dic <= n && dic > 0) {
                        cnt[dic] = 0; // 直接置为 0 表示找到了
                    }
                } catch (...) {
                    continue; // 防止极少数情况 stoi 异常
                }
            }
        }

        // 4. 检查结果
        // 从 n 遍历到 1，只要有一个没找到 (cnt[i] == 1)，就返回 false
        for (int i = n; i >= 1; i--) {
            if (cnt[i] == 1) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool queryString(string s, int n) {
        // 1. 枚举从 1 到 n 的每一个整数
        for (int i = 1; i <= n; i++) {
            
            // 2. 将整数 i 转换为 32 位二进制字符串
            // bitset<32>(i) 会把数字转为如 "00000000000000000000000000001101"
            auto bin = bitset<32>(i).to_string();
            
            // 3. 去掉前导零
            // bin.find('1') 找到第一个 '1' 出现的位置
            // bin.substr(...) 从该位置截取到最后，得到真正的二进制串，如 "1101"
            bin = bin.substr(bin.find('1'));
            
            // 4. 在原字符串 s 中查找这个二进制子串
            // string::npos 表示“没找到”
            if (s.find(bin) == string::npos)
                // 只要有一个数字没找到，立即返回 false（短路逻辑）
                return false;
        }
        
        // 5. 如果所有数字都找了一遍且都存在，返回 true
        return true;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/solutions/2265097/san-chong-suan-fa-cong-bao-li-dao-you-hu-nmtq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> seen;
        for (int i = 0, m = s.length(); i < m; ++i) {
            int x = s[i] - '0';
            if (x == 0) continue; // 二进制数从 1 开始
            for (int j = i + 1; x <= n; j++) {
                seen.insert(x);
                if (j == m) break;
                x = (x << 1) | (s[j] - '0'); // 子串 [i,j] 的二进制数
            }
        }
        return seen.size() == n;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/solutions/2265097/san-chong-suan-fa-cong-bao-li-dao-you-hu-nmtq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
