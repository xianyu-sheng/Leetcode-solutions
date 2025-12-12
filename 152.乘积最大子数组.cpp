class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            解题思路：要非空  要连续  这种怎么搞咧
            动态规划思路：
            1.首先，明确应该怎样来定义dp数组 $dp[i]$ 必须表示以 nums[i] 这个数 结尾 的连续子数组的最大乘积。
            2.确定递推公式：
                这里我们需要保证我门记录的乘积最大子数组是连续的 但是又不能一碰到负数就不干了 万一下一个也是负数呢  所以
                这里应该怎么办 
                维护两个状态  一个是以当前nums[i]结尾的最大子数组   一个是以当前nums[i]结尾的最小的子数组
                                                    Maxdp                                Mindp
                然后在面临一个nums[i]时我们更新Maxdp数组需要这样来定义递推公式：
                （1）如果是nums[i]重开户籍的话，就为nums[i]
                （2）如果是nums[i]和前面的最大积相乘【此时我们期待nums[i]为正】
                （3）如果是nums[i]和前面的最小积相乘【此时我们期待nums[i]为负】
                递推公式为Maxdp[i]=max(nums[i],max(nums[i]*maxdp[i],Mindp[i]*nums[i]))
                同理，这里我门也需要更新Mindp
                （1）单独成数组
                （2）与前面的最大数相乘 此时期望是nums[i]为负
                （3）与前面的最小数相乘 此时期望nums[i]为正
            3.首先这里初始化：可以dp[i]=nums[i]  因为抛开别的不谈 其首要的最大乘积子数组就是只有自己
        */
        int n=nums.size();
        vector<int> Maxdp(n,0);
        vector<int> Mindp(n,0);
        Maxdp[0]=nums[0];Mindp[0]=nums[0];
        for(int i=1;i<n;i++){
            //更新Maxdp
            Maxdp[i]=max(nums[i],max(nums[i]*Maxdp[i-1],Mindp[i-1]*nums[i]));
            Mindp[i]=min(nums[i],min(nums[i]*Maxdp[i-1],Mindp[i-1]*nums[i]));
        }
        //然后便利Maxdp 找出最大
        int rel=nums[0];
        for(int i=0;i<n;i++){
            if(Maxdp[i]>rel)    rel=Maxdp[i];
        }
        return rel;
    }
};