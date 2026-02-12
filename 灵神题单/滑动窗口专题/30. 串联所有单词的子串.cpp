class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //所以这个题 需要用滑动窗口来解决 然后窗口长度为数组长度*单词长度
        //同时这里可以看见的是 我们不能使用之前的比如异味单词的做法了 这里要求是以单词为基本单位 然后相等的
        vector<int> ans;
        if(s.empty() || words.empty())  return ans;
        int n=words.size(),m=words[0].size();
        if(s.size() < n*m)  return ans;
        int w=n*m;
        //然后先统计words里面的单词
        unordered_map<std::string_view,int> st;
        for(const auto& x:words)    st[x]+=1;
        //这里需要分m组滑动才能覆盖所有情况 然后内层分单词跳跃
        for(int i=0;i<m;i++){
            //这里我们来统计窗口内的单词的个数
            unordered_map<std::string_view,int> window;
            for(int j=i;j+m<=s.size();j+=m){
                //找出当前窗口内的单词
                std::string_view word = std::string_view(s).substr(j, m);
                window[word]+=1;
                //然后这里我们需要判断我们的窗口长度是不是够的
                if(j+m-w<i) continue;
                //然后就来判断是不是相等
                int left=j+m-w;
                if(window==st)  ans.push_back(left);
                //然后left开始的元素字符就减1
                std::string_view old_word=std::string_view(s).substr(left, m);
                if(--window[old_word]==0)   window.erase(old_word);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size(); // 一个单词的长度
        int window_len = word_len * words.size(); // 所有单词的总长度，即窗口大小

        // 目标：窗口中的单词出现次数必须与 target_cnt 完全一致
        unordered_map<string, int> target_cnt;
        for (auto& w : words) {
            target_cnt[w]++;
        }

        vector<int> ans;
        // 枚举第一个窗口的左端点，做 word_len 次起点不同的滑动窗口
        for (int start = 0; start < word_len; start++) {
            unordered_map<string, int> cnt;
            int overload = 0; // 统计过多的单词个数（包括不在 words 中的单词）
            // 枚举窗口最后一个单词的右开端点
            for (int right = start + word_len; right <= s.size(); right += word_len) {
                // 1. in_word 进入窗口
                string in_word = s.substr(right - word_len, word_len);
                // 下面 cnt[in_word]++ 后，in_word 的出现次数过多
                if (cnt[in_word] == target_cnt[in_word]) {
                    overload++;
                }
                cnt[in_word]++;

                int left = right - window_len; // 窗口第一个单词的左端点
                if (left < 0) { // 窗口大小不足 window_len
                    continue;
                }

                // 2. 更新答案
                // 如果没有超出 target_cnt 的单词，那么也不会有少于 target_cnt 的单词
                if (overload == 0) {
                    ans.push_back(left);
                }

                // 3. 窗口最左边的单词 out_word 离开窗口，为下一轮循环做准备
                string out_word = s.substr(left, word_len);
                cnt[out_word]--;
                if (cnt[out_word] == target_cnt[out_word]) {
                    overload--;
                }
            }
        }

        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solutions/3691292/30-ci-ding-chang-hua-dong-chuang-kou-pyt-5vgx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
