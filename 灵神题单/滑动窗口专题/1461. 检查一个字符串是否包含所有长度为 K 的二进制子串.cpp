class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //长度k虽然是固定的 但是可以不连续 也就是说这里其实是这样 通过k先生成他有那些字符串组合 然后去s中在进行滑动窗口遍历 查看是否是否有这个组合
        //如果直接生成长度为k的二进制字符串的所有情况 k的最大值为20 那么其结果将是2^20次方那么大 这样做不限时
        //但是我觉得可以转换思路 就是从字符串中每次去拿取长度为k的二进制字符串 如果是1就应该怎么减 如果是0则 不管 然后看是否能够将所有的0-2^k-1的数字都能够覆盖到 

        if(s.size() < k)    return false;
        // 用于记录已出现的长度为 k 的二进制串对应的数值
        unordered_set<int> seen;
        int total=1 << k;//2^k

        int num=0;
        int mask = (1 << k) - 1; // 提前算好
        for(int i=0;i<s.size();i++){
            //1.加入右端点
            num=(num << 1) | (s[i]-'0');
            if(i-k+1<0) continue;
            //2.加入到seen
            seen.insert(num & mask);//只取低k位
            //3.移除左端点
        }
        return seen.size()==total;
    }
};
//https://www.qianwen.com/share/chat/f1d0a6b8f4e24bfdbeaeb1188afd53df
//学习疑问链接

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for (int i = k; i <= s.size(); i++) {
            st.insert(s.substr(i - k, k));
        }
        return st.size() == (1 << k);
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solutions/3902489/liang-chong-fang-fa-bao-li-wei-yun-suan-4wnph/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
