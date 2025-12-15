/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            解题思路：第一点，相邻的房屋不能一起加入   这个就是限制条件 其他的就可以转换为01背包问题
            怎样来记录呢  我们可以在外层遍历物品 内层遍历房屋  使用一个两行的数组来进行记录
            动态规划五部曲：
            1.dp[i]  这个数组的第一行是我用来构造一维dp数组的行 这一行与正常的dp数组无差别  就是记录打劫前i房子 能够打劫到的最大金额  
            2.推导dp数组公式:要么就是不装 那么dp[i]=dp[i-1]  要么装  选择相邻两个房子之间更大的那一间装
            dp[i]=max(dp[i-1],dp[i-1]-nums[i-1]+nums[i])
            3.遍历顺序：外层遍历房子   内层代表背包 背包没有上限
            4.初始化dp数组：dp(nums.size()+1,0) 

            改变思路：我们是要选择尽可能的多的   那么背包容量首先怎么定义？   沿用之前最后的 石头重量的方法  选出两个堆  然后总数减小的那个堆  就是我们需要选择的房屋能够打劫到的最大的数量
        */
        int n=nums.size();
        if(n==1)    return nums[0];
        vector<int> dp(n,0);
        //接下来就是处理n>=4的情况
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            解题思路：一个房屋有两种的状态，要么被偷要么不被偷，而当前的房屋的状态基于前一个房屋的状态，也就是前一个房屋是否被偷
            这里我认为可以定义一个两个空间的dp数组，dp[0]代表偷当前房子，dp[1]代表不偷当前房子的最大金额

            动态规划五部曲：
            1.定义dp数组含义以及下标的含义，dp[0]代表当前房子被偷的最大金额，dp[1]代表当前房子不被偷的最大金额
            2.定义递归公式：当前的dp[0]=之前的dp[1]+当前房子的金额，dp[1]=之前的dp[0],dp[1]中的大值，因为我这一家不透，那么我前一天偷还是不透其实都无所谓 这样交替的进行 最后返回dp[0]与dp[1]中最大的那个值
        */
       vector<int> dp(2,0);
        dp[0]=nums[0];
        dp[1]=0;
        for(int i=1;i<nums.size();i++){
            int dp_0=dp[1]+nums[i],dp_1=max(dp[0],dp[1]);
            dp[0]=dp_0;dp[1]=dp_1;
        }
        return dp[0]>dp[1]?dp[0]:dp[1];
    }
};
// @lc code=end

