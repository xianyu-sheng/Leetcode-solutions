class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        /*
            统计最大元素出现至少 K 次的子数组：
            1.先统计最大元素
            2.然后就.....
            这里可能ans 越界 需要mod
        */
        int max_num=INT_MIN;
        for(int x:nums) max_num=max(x,max_num);

        //然后开始来统计至少是不是出现了k次
        long long ans=0;
        int count=0;
        for(int l=0,r=0;r<nums.size();r++){
            if(nums[r]==max_num)    count++;
            //然后来统计
            while(count>=k){
                if(nums[l]==max_num)    count--;
                l++;
            }
            ans+=l;
        }
        return ans;
    }

};
