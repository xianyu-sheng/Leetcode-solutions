/*
 * @lc app=leetcode.cn id=2054 lang=cpp
 *
 * [2054] 两个最好的不重叠活动
 */

// @lc code=start
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        /*
            解题思路：
            1.按时间顺序看活动：先把所有活动按照开始时间拍个序，这样我们从早到晚一个个看
            2.维护历史最佳：当我们看到第i个活动时，我们需要指导在这个活动开始之前，所有已经结束的活动里，价值最高的是多少
            这样直接就是很直接的思路，就是找两个最大的组合
        */

        //1.首先按照开始时间排序
        sort(events.begin(),events.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });

        //2.然后建立一个最小堆，来维护在后面的开始时间前就结束的活动  <结束时间，价值>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        //3.定义最大值，结果
        int max_val=0,ans=0;

        //4.然后开始遍历events数组
        for(auto event : events){
            //从堆里取数据出来，更新在本事件开始之前的最大价值max_value
            while(!min_heap.empty() && min_heap.top().first<event[0]){
                auto temp=min_heap.top();min_heap.pop();
                max_val=max(max_val,temp.second);
            }
            //然后更新结果
            ans=max(ans,max_val+event[2]);
            //当前数据入堆
            min_heap.push(pair<int,int>{event[1],event[2]});
        }
        return ans;
    }
};
// @lc code=end

