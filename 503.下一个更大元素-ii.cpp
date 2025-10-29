/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
            题意理解：循环数组 也就是说 相当于最后一个数组的下一个更大元素应该在前面来找
            那既然这样我是否可以单独处理这一部分逻辑呢？  ----->不行 我们应该明白的是 如果我们首尾相连 那么如果我们倒数第二个的下一个更值不是nums[legnth-1]呢  而是前面的元素呢 这种情况应该如何处理 究竟如何处理环形的数组呢？
            我们是否可以使用一个双向队列来完成这个工作  在我们初次遍历这个数组的时候 还是先将其当做栈来使用 当我们遍历完一次nums数组之后 就开始在队列的前端做文章
            或者说我们应该遍历整个数组两次 那怕这是一个环形的数组那么 我们最多就是遍历到一个数两次那么也就终止了 获得了我们想要的答案
        */
        vector<int> rel(nums.size(),-1);
        stack<int> st;
        for(int times=0;times<2;times++){
            for(int i=0;i<nums.size();i++){
                while(!st.empty() && nums[i]>nums[st.top()]){
                    //取出栈定元素
                    int prev_index=st.top();
                    st.pop();
                    rel[prev_index]=nums[i];
                }
                st.push(i);
            }
        }
        return rel;
    }
};
// @lc code=end

