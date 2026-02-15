class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        /*
            限制条件1：如果两个相邻房间的颜色代码相同则不能够同时抢劫 
            我们需要返回的是最大金额 动态规划五部曲

            1.dp[i]以及i的含义：dp[i]->抢劫到0-i这些房屋所获得的最大的金额
            2.递归公式推导：其实际上就是一个抢与不抢的问题 如果要抢的话 即当前的相邻的邻居的颜色代码是不相同的 那么我们可以直接抢
            那不抢的话 就是颜色代码相同的 那么我们就是要抉择是当前的这个房间不抢 还是前一个房间不抢 选择一个较大值作为当前房屋的抢劫总值
            3.遍历顺序：外层背包 内层是nums
            4.初始化为当前的元素都是0
        */
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<long long> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            //如果颜色相同
            if(colors[i]!=colors[i-1]){
                dp[i]=dp[i-1]+nums[i];
            }else{
                //颜色相同来比较选择当前元素还是前一个元素
                long long skip_num=dp[i-1];
                long long rob_num=(i>=2 ? dp[i-2]:0)+nums[i];
                dp[i]=max(skip_num,rob_num);
            }
        }
        return dp[n-1];
    }
};©leetcode
