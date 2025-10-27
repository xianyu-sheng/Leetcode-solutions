/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> rel(size,0);
        stack<int> st;
        for(int i=0;i<size;i++){
            while(!st.empty()  && temperatures[i] > temperatures[st.top()]){
                int prev_index=st.top();
                st.pop();
                rel[prev_index]=i-prev_index;
            }
            st.push(i);
        }
        return rel;
    }
};
// @lc code=end

