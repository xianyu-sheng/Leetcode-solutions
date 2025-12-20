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
//方法2
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            题意理解：在这个题中我们其实可以采用一个中心扩散法，就是假设每一个柱子我们都可以将
            其设为高度，然后看以它为高度，我们的矩形面积到底有多大，可以有多大，然后我们又可以
            根据木桶原理，决定我们矩形的高度的就是这个矩形中的柱形的最低的那个柱形，因此为了能够
            计算出以当前柱子为最低的哪个柱子的矩形面积，我们就需要保持住在这个矩形中，当前的这个矩形
            中当前的柱形的高度最低，这时候我们需要维护这个矩形满足这个木桶原理的边界，因此我们使用
            两个数组来维护两边的边界
        */
        int n=heights.size();
        if(n==0)    return 0;

        vector<int> minleftindex(n);
        vector<int> minrightindex(n);
        
        //然后进行左右两边第一个比自己小的柱形下标的统计
        minleftindex[0]=-1;
        for(int i=1;i<n;i++){
            int t=i-1;
            while(t>=0 && heights[t]>=heights[i]){
                t=minleftindex[t];
            }
            minleftindex[i]=t;
        }
        minrightindex[n-1]=n;
        for(int i=n-2;i>=0;i--){
            int t=i+1;
            while(t<n && heights[t]>=heights[i]){
                t=minrightindex[t];
            }
            minrightindex[i]=t;
        }
        //然后遍历所有柱子 计算最大的矩形的面积
        int rel=INT_MIN;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int w=minrightindex[i]-minleftindex[i]-1;//去掉两侧比自己小的柱形，只留这块自己是最小的宽度
            rel=max(rel,h*w);
        }
        return rel;
    }
};
// @lc code=end

