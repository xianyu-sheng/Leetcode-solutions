class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
            乘积小于K的子数组 一般如果需要算乘积的话  这里推荐倒序的来进行计算 防止除法
            乘积小于k 那么如果目前乘积大于k 那么就一直移动左端点
        */
        //如果k<=1  那么直接为0
        if(k<=1)    return 0;
        int prod=1;//乘积
        int ans=0;//满足条件的个数
        for(int l=0,r=0;r<nums.size();r++){
            prod*=nums[r];
            //然后如果此时prod大于等于k  那么就需要移动左端点
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            //然后这里来统计满足条件的子数组个数
            ans+=(r-l+1);
        }
        return ans;
    }
};
