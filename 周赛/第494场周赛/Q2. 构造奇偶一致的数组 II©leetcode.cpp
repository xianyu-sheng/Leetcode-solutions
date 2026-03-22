class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //这里代表什么 不要求顺序 那么我们可以先将这个排序之后来
        sort(nums1.begin(),nums1.end());
        //然后来统计这个奇数数目 以及偶数出现的地方  第一个偶数出现的地方 后面我们就直接奇数-去这个就行
        int odd=0,first_even_index=-1;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1){
                odd++;
                if(first_even_index==-1)
                    first_even_index=i;
            }
        }
        //odd==0
        if(odd==0)
            return true;
        //然后对于>0的情况
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1)
                continue;
            else{
                //如果此时为偶数
                if(i<first_even_index)
                    return false;
            }
        }
        return true;
    }
};©leetcode
