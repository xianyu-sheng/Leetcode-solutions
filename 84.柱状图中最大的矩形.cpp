/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            题意理解：这个柱状图 我们需要勾勒出最大的的矩形 那么就按照木桶原理
            应该按照最矮的柱子来进行计算 每次往栈里放进去小的 就是这样的情况
            第一，如果当前遍历的元素系小于栈顶元素 那么就弹出栈顶元素  将这个加入进去
            第二，如果当前的元素大于栈顶元素 那么就弹出栈顶元素 计算当前的矩形面积 并更新
            第三，如果当前的元素等于栈顶元素 那么就更新栈顶元素的下标
            其中2和3 可以归结为一类 都需要更新max_rel
        */
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);

        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) { // 情况一
                st.push(i);
            } else if (heights[i] == heights[st.top()]) { // 情况二
                st.pop(); // 这个可以加，可以不加，效果一样，思路不同
                st.push(i);
            } else { // 情况三
                while (!st.empty() && heights[i] < heights[st.top()]) { // 注意是while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};
// @lc code=end

