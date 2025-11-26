/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*
            查找共用字符：26个字符我们可以使用这样的解决方法 在每个words中我们统计出现的字符的共同次数中的最小次数
            也就是大家都有这些
        */
        vector<int> min_freq(26,INT_MAX);
        vector<string> rel;

        for(const string& word : words){
            vector<int> freq(26,0);
            for(char c : word){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                min_freq[i]=min(min_freq[i],freq[i]);
            }
        }

        //然后进行统计
        for(int i=0;i<26;i++){
            for(int j=0; j < min_freq[i];j++){
                rel.push_back(string(1,'a'+i));
            }
        }
        return  rel;
    }
};
// @lc code=end

