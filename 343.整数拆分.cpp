/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        /*
            动规五部曲：
            1、确定dp[i]及其下标含义：i代表的既是n,dp[i]代表的就是n拆分后得到的最大乘积
            2、确定递推公式：从题目来看我们可以明白的是，当n=2时，我们可以可以拆为1+1  这是唯一结果 最大乘积为1
            当n=3时。可以拆分为1+2  乘积为2  2又可以拆分为1+1  那么3也可以拆分为1+1+1  此时乘积为1   最大乘积应该为2
            当n=4时，可以拆分为1+3  乘积为3 3(已经拆分过))的最大乘积为2  所以此次拆分最大乘积为3
                    4还可以拆分为2+2  乘积为4------------>最大乘积
            ......
            因此初步可以定义状态转移方程应该为dp[i]=max(当前已经遍历到的最大乘积值，max(j*(i-j),j*dp[i-j]))
                                                                              不继续拆分    继续拆分
            3、初始化为dp[1]=1,dp[2]=1;
        */
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            int max_val=0;//记录每个n的最大乘积
            for(int j=1;j<i-1;j++){
                //我这个也算是看着答案理解的哈 我认为这里j<i-1的原因是 这里最小拆分到2就可以了 i-j=1没有意义
                max_val=max(max_val,max(j*(i-j),j*dp[i-j]));
            }
            dp[i]=max_val;
        }
        return dp[n];
    }
};
// @lc code=end

