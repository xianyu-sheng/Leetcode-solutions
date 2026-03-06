class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //求最大子数组的和 这里能够使用贪心来求解吗 贪心的思想是通过求局部的最优解来达成全局的最优解 那么在这里我个人感觉就不是很好用了---这里可以使用前缀和+贪心来组合解决这个题
        //因此这里我选择使用动态规划 可以传递状态即使我前面一个值是负数 但是加上了当前的这个值 比当前的最大值更大 我觉得也是可取的

        //1.动态规划
        int n=nums.size(),rel=nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            rel=max(rel,dp[i]);
        }
        return rel;
    }
};

//2.前缀和+贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //前缀和+贪心
        int ans=INT_MIN;
        int min_pre_sum=0;
        int pre_sum=0;

        for(int x:nums){
            pre_sum+=x;

            ans=max(ans,pre_sum-min_pre_sum);//减去前缀和的最小值
            min_pre_sum=min(min_pre_sum,pre_sum);//维护前缀和的最小值
        }
        return ans;
    }
};
