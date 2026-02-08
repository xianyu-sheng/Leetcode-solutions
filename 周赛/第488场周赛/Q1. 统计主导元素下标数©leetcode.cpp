class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        /*
            1.数组的最右边实际上是不便利的
            2.算主导元素-->后缀和
        */
        int ans=0;//记录主导元素
        int n=nums.size();
        vector<int> presum(n,-1);
        //计算后缀和
        int sum=0;
        for(int i=n-1;i>0;i--){
            sum+=nums[i];
            presum[i-1]=sum;
        }
        //然后来正序便利
        for(int i=0;i<n-1;i++){
            int len=n-i-1;
            double average=(double)presum[i]/len;
            if(nums[i]>average)
                ans++;
        }
        return ans;
    }
};©leetcode
//参考答案
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        long long sm = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && 1LL * nums[i] * (n - i - 1) > sm) ans++;
            sm += nums[i];
        }
        return ans;
    }
};
