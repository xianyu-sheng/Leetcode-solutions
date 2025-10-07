/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
/*
    这里刚开始我混淆了最长公共子序列 与 最长的公共子数组的差别 公共的子数组他的这些
    元素必须是连续的  而最长公共子序列不必连续  只要保持相对顺序即可  下面是最长
    公共子序列与最长公共子数组的区别的AI聊天对话的记录
    https://lxblog.com/qianwen/share?shareId=1fd52cb0-fab5-4d07-b64e-d437bb875594
 */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*
            解题思路：按照01背包的思路来解决问题
            状态转移公式为  dp[i][j]=max(dp[i-1][j-1]+1,dp[i-1][j]+1)
            初始化时  应该初始化第一行以及第一列
        */
        vector<vector<int>> dp(nums2.size(),vector<int>(nums1.size(),0));
        int  max_rel=0;
        //初始化第一行
        for(int i=0;i<nums1.size();i++){
            if(nums2[0]==nums1[i]){
                dp[0][i]=1;
                max_rel=max(max_rel,1);
            }  
        }
        //初始化第一列
        for(int i=0;i<nums2.size();i++){
            if(nums1[0]==nums2[i]){
                dp[i][0]=1;
                max_rel=max(max_rel,1);
            }  
        }
        //进行dp数组的推导
        for(int i=1;i<nums2.size();i++){
            for(int j=1;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_rel=max(max_rel,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return max_rel;
    }
};
// @lc code=end

