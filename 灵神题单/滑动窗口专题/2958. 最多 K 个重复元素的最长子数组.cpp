class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        /*
            使用哈希表来存储频次，然后来进行统计 返回最长
        */
        int ans=0;
        unordered_map<int,int> mymap;
        for(int l=0,r=0;r<nums.size();r++){
            //进窗口
            mymap[nums[r]]++;
            while(mymap[nums[r]]>k){
                mymap[nums[l]]--;
                l++;
            }
            //此时窗口内的元素都是满足的
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
