class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        //怎样使用滑动窗口来解决这个问题？
        //首先，我们应该需要排除的就是 每次窗口移动就全量的计算一次整个哈希 这里我觉得其实可以这样
        //维护一个sum来计算(val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1)  这一串的和 然后移动的话 左边就直接减去val(s[0]) 然后剩下的这部分乘以一个p^(-1) 然后 再加上右边的值
        //然后又要返回第一个 那我们就直接就维护一个窗口就行了
        // 必须使用 long long，因为中间计算过程 val * pk 即使取模也可能溢出 int
        long long cur = 0;
        long long pk = 1; // 这个用来存 power^(k-1)
        int n = s.length();
        int resIndex = 0; // 记录答案的起始位置

        // 1. 先预计算 power^(k-1) % modulo
        // 这一步是为了后面方便移除窗口最右边的元素（也就是公式里的最高位）
        for (int i = 0; i < k - 1; i++) {
            pk = (pk * power) % modulo;
        }

        // 2. 从字符串末尾开始，从右向左滑动
        for (int i = n - 1; i >= 0; i--) {
            // 如果窗口长度超过了 k，需要把最右边那个老元素踢出去
            // 最右边的元素在公式里是乘以 p^(k-1) 的，所以减去 val * pk
            if (i + k < n) {
                int remove_val = s[i + k] - 'a' + 1;
                // 注意：减法取模可能会出现负数，所以要 + modulo 再 % modulo
                cur = (cur - (remove_val * pk) % modulo + modulo) % modulo;
            }

            int val = s[i] - 'a' + 1;
            
            // 核心逻辑：
            // 以前的哈希值整体左移一位（乘以 power），此时原本的 p^0 变成了 p^1
            // 当前的新字符 s[i] 放在 p^0 的位置（直接加 val）
            cur = (cur * power + val) % modulo;
            
            // 检查是否符合条件
            // 题目要求返回“第一个”符合的子串。
            // 因为我们是倒序遍历，最后一次找到的匹配位置 i，就是原字符串中最靠左的那个。
            if (i+k <= n && cur == hashValue) {
                resIndex = i;
            }
        }

        return s.substr(resIndex, k);
    }
};

//灵神的定长窗口套路模板写法
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long cur = 0;
        long long pk = 1; // 这个用来存 power^(k-1)
        int n = s.length();
        int resIndex = 0; // 记录答案的起始位置

        // 1. 先预计算 power^(k-1) % modulo
        // 这一步是为了后面方便移除窗口最右边的元素（也就是公式里的最高位）
        for (int i = 0; i < k - 1; i++) {
            pk = (pk * power) % modulo;
        }

        // 2. 从字符串末尾开始，从右向左滑动
        for (int i = n - 1; i >= 0; i--) {
            //左端点进
            int val = s[i] - 'a' + 1;
            cur = (cur * power + val) % modulo;
            //检查窗口长度条件是否达成
            int right=i+k-1;
            if(right>=n)    continue;
            if (cur == hashValue) {
                resIndex = i;
            }
            //移除右端点
            int remove_val = s[right] - 'a' + 1;
            // 注意：减法取模可能会出现负数，所以要 + modulo 再 % modulo
            cur = (cur - (remove_val * pk) % modulo + modulo) % modulo;
        }
        return s.substr(resIndex, k);
    }
};
//灵神写法
class Solution {
    // 快速幂
    // https://leetcode.cn/problems/powx-n/
    long long qpow(long long x, int n, int mod) {
        long long res = 1 % mod;
        for (; n > 0; n /= 2) {
            if (n % 2 > 0) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n = s.size();
        long long p = qpow(power, k - 1, mod);
        long long hash = 0;
        int ans_left; // 题目保证答案存在

        for (int i = n - 1; i >= 0; i--) { // 倒着滑窗
            // 1. 左端点进入窗口
            hash = (hash * power + (s[i] & 31)) % mod;

            int right = i + k - 1; // 窗口右端点
            if (right >= n) { // 窗口大小不足 k，尚未形成第一个窗口
                continue;
            }

            // 2. 更新答案
            if (hash == hashValue) {
                ans_left = i;
            }

            // 3. 右端点离开窗口，为下一个循环做准备
            hash = (hash - (s[right] & 31) * p % mod + mod) % mod; // +mod 保证结果非负
        }

        return s.substr(ans_left, k);
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-substring-with-given-hash-value/solutions/1239542/dao-xu-hua-dong-chuang-kou-o1-kong-jian-xpgkp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/*
    s[i]&31  为什么可以这样操作
    s[i] & 31：保留字符 s[i] 八位二进制位的后五位。

    a ~ z 的 ASCII 码为: 011 00001 ~ 011 11010，保留后五位，即 000 00001 ~ 000 11010，正好是 1 ~ 26
*/
