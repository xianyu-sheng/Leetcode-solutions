/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
            这里首先应该创建一个ans数组，大小为nums1.size()
            然后创建一个stack栈，往里面去

            也就是对与每一个nums[i]  先在nums2中找到他 然后在继续找第一个大的值
            但是这里不得行 就是为什么因为可能我们有一个元素直到nums2搜搜结束后 还是没有找到比他大的元素 然后我们就会又从nums2开头开始搜索 这样做时间复杂度太大

            哪一个比较笨的办法 就是先将nums1中所有元素的对应位置找出来 然后再对nums2求下一个更大元素 然后将对应位置的值更新到nums1的结果数组
        */
        //先取对应位置
        vector<int>  pos(nums1.size(),0);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    pos[i]=j;
                    break;
                }
            }
        }
        //然后让nums2来进行找下一个更大的元素的逻辑
        vector<int> rel_nums2(nums2.size(),-1);
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                int prev=st.top();
                st.pop();
                rel_nums2[prev]=nums2[i];
            }
            st.push(i);
        }
        vector<int> rel(nums1.size(),-1);
        //然后直接找到对应位置的下一个跟答元素
        for(int i=0;i<pos.size();i++){
            rel[i]=rel_nums2[pos[i]];
        }
        return rel;
    }
};
// @lc code=end

