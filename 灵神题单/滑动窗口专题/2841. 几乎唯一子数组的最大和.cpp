class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        /*
            对于这题我们的要求是 第一，长度为k 然后我们需要这个长为k的子数组他的里面有至少m个不同的元素 那么这里
            如果m>k 那么直接就返回0
            如何来判定是不是满足m个不同的数值 需要借助哈希表来进行判断
        */
        long long ans=0;//来存储最大的子数组和
        long long sum=0;//使用这个来存储局部的数组和
        unordered_map<int,int> counts;//用来存储有哪些不同的元素
        int diffcount=0;//用来存储是不是有m个不同的元素
        for(int i=0;i<nums.size();i++){
            //1.进窗口
            sum+=nums[i];
            if(counts[nums[i]]==0)  diffcount++;
            counts[nums[i]]++;
            //2.然后来检查当前是不是够k
            if(i-k+1<0) continue;
            //3.如果大于了 那么此时就再来判断是不是有m个不同的元素以来更新最大和
            if(diffcount>=m)    ans=max(ans,sum);
            //4.最后的一个元素退出
            sum-=nums[i-k+1];
            counts[nums[i-k+1]]--;
            if(counts[nums[i-k+1]]==0)  diffcount--;
        }
        return ans;
    }
};
