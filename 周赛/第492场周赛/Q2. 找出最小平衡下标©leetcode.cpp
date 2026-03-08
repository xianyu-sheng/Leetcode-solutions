class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        //维护前缀和+后缀乘积
        //当前的前缀和i值等于0-i-1的和  当前的后缀乘积等于n-1到i+1的值
        //找出最小平衡下标  找出一批下标 然后返回最小值
        int n=nums.size();
        int mod=INT_MAX;
        vector<long long> pre_sum(n,0);
        vector<long long> post_mul(n,1);

        //计算前缀和
        for(int i=1;i<n;i++){
            pre_sum[i]=(pre_sum[i-1]+nums[i-1])%mod;
        }
        //计算后缀乘积
        for(int i=n-2;i>=0;i--){
            post_mul[i]=(post_mul[i+1]*nums[i+1])%mod;;
        }
        //然后开始遍历 从前往后遍历  遇到了直接break
        int ans=-1;
        for(int i=0;i<n;i++){
            if(pre_sum[i]==post_mul[i]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};©leetcode
