/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /*
            理解题意：绘制的直线不能与任何其他连线相交---->这句话的意思我认为可以抽象成理解为一个01背包的问题
            然后呢？还可以怎么理解？我们前面一直讲的是子序列 连续啊  递增什么的？其实看这里可以抽象为一个我们要去求两个数组中的最长的子序列长度 当然需要保持顺序

            解题思路：可以按照解答最长子序列的解法来解答这个问题我认为 
            即如果 nums1[i] == nums2[j]    则dp[i+1][j+1]=dp[i][j]+1
            如果nums1[i]≠nums2[j]  则dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
        */
        int n=nums1.size();
        int m=nums2.size();
        // dp[i][j]: nums1[0:i] 和 nums2[0:j] 的最长公共子序列长度
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

