/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    /*
        解题思路：这道题的难点是我取得是中位数，但是中位数是需要数组在排序的前提下进行计算的
        因此我们这道题需要的就是维护动态的有序 但是应该怎样维护呢？如果我单纯的维护一个大顶堆或者是一个小顶堆
        那么我后面弹出数据也还是需要一个个弹出  这样时间上仍然会超时 不符合困难题对时间开销的要求
        因此这里我们需要使用一个大顶堆以及一个小顶堆 而大顶堆里放较小的元素  小顶堆里放较大的元素，这样我们才能够直接从堆顶
        拿出中间的元素
    */
    priority_queue<int> max_que;
    priority_queue<int,vector<int>,greater<int>> min_que;
    MedianFinder() {
    }
    
    void addNum(int num) {
        //这里的放入放顺序很有讲究 先将元素放入大顶堆  然后在将堆顶的元素放到小顶堆 并维持平衡
        max_que.push(num);
        min_que.push(max_que.top());
        max_que.pop();

        if(max_que.size() < min_que.size()){
            max_que.push(min_que.top());
            min_que.pop();
        }
    }
    
    double findMedian() {
        //如果大顶堆多一个
        if(max_que.size() > min_que.size()) return max_que.top();
        return (max_que.top()+min_que.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

