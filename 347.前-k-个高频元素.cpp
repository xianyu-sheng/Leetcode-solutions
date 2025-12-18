/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    // 1. 定义一个仿函数（结构体），用于比较逻辑
    struct Compare {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            // 我们需要小顶堆，意味着频率小的在堆顶
            // C++ priority_queue 默认是大顶堆，根据 comparator 规则：
            // 如果返回 true，b 会排在 a 前面（或者理解为 a 的优先级比 b 低）
            // 这里我们需要 second (频率) 小的优先级高（浮在堆顶），所以要反着写
            return a.second > b.second; 
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 使用 map 统计频率
        unordered_map<int, int> mymap;
        for (int num : nums) {
            mymap[num]++;
        }

        // 2. 定义优先级队列
        // 参数：<数据类型, 容器类型, 比较方法>
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_que;

        // 遍历 map
        for (auto& t : mymap) {
            min_que.push(t);
            // 3. 维护堆的大小为 k
            // 如果超过 k，就把堆顶（频率最小的那个）弹出去
            // 剩下的自然就是频率最大的 k 个
            if (min_que.size() > k) {
                min_que.pop();
            }
        }

        // 4. 取出结果
        vector<int> rel;
        while (!min_que.empty()) {
            rel.push_back(min_que.top().first);
            min_que.pop();
        }
        
        return rel;
    }
};
// @lc code=end

