/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
            使用优先级队列来解决问题，这里我们需要的是在自己定义一个比较函数-->来告诉优先级队列我的较大的数值
            排前面，然后再依次取出第K个元素就好
        */
        priority_queue<int> pre_que;//默认为大顶堆
        //然后依次将数组中的数据取出放到pre_que中
        for(int i=0;i<nums.size();i++){
            pre_que.push(nums[i]);
        }
        //然后倒序取出第k各元素
        int rel=-10001;
        while(k--){
            rel=pre_que.top();pre_que.pop();
        }
        return rel;
    }
};
// @lc code=end

