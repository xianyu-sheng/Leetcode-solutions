/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
            题目思路：当i>=cost.size()时，判断为到达楼梯顶部
            思考一下：怎样可以使用动态规划算法来解决这一道问题，动态规划--->本阶段的状态依赖于前面的状态，那么本题是要求最小花费到楼梯顶部，可以选择从0或1开始出发---->那么这就是两个初始状态---->选择只上一个台阶就暂定为已经到cost.size()-1了
        */
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};
// @lc code=end

