/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /*
        解题思路：这里这个题应该怎么解决？咋一看，是需要在这样minstack里面封装一个
        小顶堆，但是这里我们还需要考虑的是什么呢？如果我正常的弹出堆顶的元素，那么我
        在小顶堆中如何进行设计，这样只能是一个个弹出了怎么办？
        那我只使用一个数字来存储好像也不太行，因为如果我的这个最小值刚好是栈顶，那么就需要进行最小值的更新
        这里我干脆就使用一个双端队列吧 最小的一直在前面 大的在后面

        经过使用小顶堆的使用，发现AC不了，这里想到的问题是：第一，使用小顶堆固然可以让我们对于最小值有记忆功能，
        但是其本身的时间复杂度是我们不能接受的，并且堆（Heap）无法像栈一样“后进先出”地精确撤销操作，导致非最小值的删除会破坏数据一致性。
    */
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
        //首先将其压入栈
        st.push(val);
        if(val<=min_st.top())
            min_st.push(val);
    }
    
    void pop() {
        //这里如果是栈顶的元素恰好是最小元素 才对小顶堆进行更新
        if(st.top()==min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

