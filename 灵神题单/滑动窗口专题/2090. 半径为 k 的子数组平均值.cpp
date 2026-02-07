class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //这里就是讲平均值放入到数组中
        //但是这里我们是需要加入进去一个半径的概念  满足半径我们才进行记录 那么如果先找到i然后再去找后半段 那么我们的时间复杂度会达到O(n*k) 为降低时间复杂度  我们可以以直径(2*k+1)来进行计算
        //但是这样不行，因为比如最后一个元素以他为中心然后其半径应该是-1的 那么按照我前面的解法就是给他一个合法值
        /*
        不过做的并不好 我感觉其实可以这样来做就是 如果左边不够也就是i-k<0 那么直接在这i这里像结果数组push-1 然后同理如果右边不够i+k 也就是i+k越界了 那么就也向ans里push -1 然后中间的部分就看作是一个2*k+1长的滑动串口 
        */
        int n=nums.size();
        vector<int> ans(n,-1);
        long long sum=0;
        int len=2*k+1;
        if(n<len)  return ans;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            //1.检查当前的长度是否满足了窗口的长度
            if(i-len+1<0)   continue;
            //2.否则就是够的 那么就开始计算并加入
            ans[i-k]=sum/len;
            //3.弹出最左端窗口的元素
            sum-=nums[i-len+1];
        }
        return ans;
    }
};
