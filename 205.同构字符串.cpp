/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_to_t;
        unordered_map<char,char> t_to_s;

        for(int i=0;i<s.size();i++){
            char sc=s[i];
            char tc=t[i];

            if(s_to_t.count(sc)){
                if(s_to_t[sc]!=tc)  return false;
            }else{
                s_to_t[sc]=tc;
            }

            if(t_to_s.count(tc)){
                if(t_to_s[tc]!=sc)  return false;
            }else{
                t_to_s[tc]=sc;
            }
        }
        return true;
    }
};
// @lc code=end

