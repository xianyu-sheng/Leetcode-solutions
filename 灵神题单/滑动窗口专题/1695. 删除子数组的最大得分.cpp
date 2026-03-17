class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        /*
            这个题就是需要模拟删除  这里要求若干不同的元素 那么这里还需要一个哈希表来记录次数 保证每个元素的出现次数为1
        */
        int ans=0;
        int cur_ans=0;//用来统计当前窗口的最大得分
        unordered_map<int,int> mymap;
        for(int l=0,r=0;r<nums.size();r++){
            mymap[nums[r]]++;
            cur_ans+=nums[r];
            //去重
            while(mymap[nums[r]]>1){
                mymap[nums[l]]--;cur_ans-=nums[l];
                l++;
            }
            ans=max(ans,cur_ans);
        }
        return ans;
    }
};
