class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        /*
            abs(i - j) <= indexDiff  ----->映射为[max(0,(i-indexDiff)),i]
            abs(nums[i] - nums[j]) <= valueDiff  --->在上面这个窗口内的元素 查找有没有存在于[nums[i]-valueDiff,nums[i]+valueDiff]的数据
        */
        set<long long> st;
        for(int i=0;i<nums.size();i++){
            //3.检查当前窗口内是否有满足条件的数
            auto lb=st.lower_bound((long long)nums[i]-valueDiff);
            if(lb!=st.end() && *lb<=(long long)nums[i]+valueDiff)   return true;
            st.insert(nums[i]);
            //4.弹出左边界
            if(i>=indexDiff)
                st.erase(nums[i-indexDiff]);
        }
        return false;
    }
};
