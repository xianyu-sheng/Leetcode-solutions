/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
            解题思路：stones[i]代表着与背包问题中的价值 也即是 体积
            如何转化为01 背包问题呢？？？
            每次都是两两做减法-->然后每次两两做减后让你返回最小的一块石头，要最小，那么我们每次就选择两个重量接近的狮驼
            因此我这里想的就是将所有石头分为两个和最接近的子集，然后做差值就可以得到最小的一块的石头的重量
            ----------------------------sum/2------------------------------------
                                    ^较小的子集  ^较大的子集
            因此就可以延续  416.分割等和子集 的想法 看看怎样可以在体积为sum/2中得到较小的子集  然后在较大的子集-这个较小的子集和
        */
        int sum=0;
        for(int i=0;i<stones.size();i++)
            sum+=stones[i];
        //然后构造dp数组等
        int target=sum/2;
        vector<int> dp(target+1,0);
        for(int i=0;i<stones.size();i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-dp[target]-dp[target];
    }
};
// @lc code=end

