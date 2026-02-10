//基础版：思路完成
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        /*
            1.不同字母的树木必须小于等于maxLeeters
            2.子串的长度必须[minSize,maxSize]
            这里怎样思考呢？如果s.size()>maxSize 那我干脆是不是就可以直接使用maxSize当做窗口呢？
            也不是 那么如果明明我们在区间内达到了最大这样会失去机会 这里还必须使用两个容器一个unordermap来记录所有满足条件的子串 然后unorderedmap才可以  避免有多个相同元素在区间内

            但是这个思路是有错误的 其实应该是使用minSize来做定长的窗口 因为如果按照我们实际题目条件选出的字符串他满足的条件那么其只有minSize长的子串也必然满足
        */
        int rel=0;
        unordered_map<string,int> ans;//用来统计结果
        unordered_map<char,int> st;//用来统计子串内的字母数量
        for(int i=0;i<s.size();i++){
            //1.加入右端点
            st[s[i]]+=1;
            //2.检查窗口大小
            if(i-minSize+1<0)   continue;
            //3.窗口大小够 检查是否满足条件
            int left=i-minSize+1;
            if(st.size()<=maxLetters){
                string sub=s.substr(left,minSize);
                ans[sub]+=1;
                //更新
                rel=max(rel,ans[sub]);
            }
            //4.减去左端
            char out=s[left];
            if(st[out]>1)   st[out]-=1;
            else    st.erase(out);
        }
        return rel;
    }
};
//优化版
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        if (n < minSize) return 0;

        unordered_map<string_view, int> counts; // 使用 string_view 避免拷贝字符串
        int char_cnt[26] = {0};
        int unique_chars = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            // 1. 右端点进入
            if (char_cnt[s[i] - 'a']++ == 0) unique_chars++;

            // 2. 窗口过大时移除左端点 (维持长度为 minSize)
            if (i >= minSize) {
                if (--char_cnt[s[i - minSize] - 'a'] == 0) unique_chars--;
            }

            // 3. 只有当窗口长度正好为 minSize 且满足字母种类限制时
            if (i >= minSize - 1 && unique_chars <= maxLetters) {
                // string_view 是 C++17 特性，指向原字符串的内存，不产生拷贝
                string_view sub(s.data() + i - minSize + 1, minSize);
                res = max(res, ++counts[sub]);
            }
        }
        return res;
    }
};
