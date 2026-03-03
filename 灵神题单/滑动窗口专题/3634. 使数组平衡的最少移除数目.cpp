//最初的解法
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        /*使数组平衡的最少移除数目
            这里其实也是求的是满足条件的子数组 最少的移除数目 那么也就意味着 数组原本的长度-满足平衡条件的最长子数组的长度
            那么这里关键的是怎样维护当前窗口的最大值 最小值 并且在窗口移动的时候 还需要变化 因此不能简单的就使用两个变量来维护
            然后什么时候移动---如果最大值>k*最小值 那么就需要移动
        */
        //使用set来动态的维护最大值最小值
        //先排序 将可以不连续的移除的逻辑转换为必须使用连续移除的逻辑
        sort(nums.begin(),nums.end());
        multiset<int> st;
        int left=0,ans=0;//求最长的长度
        for(int i=0;i<nums.size();i++){
            //1.加入到set
            st.insert(nums[i]);
            //2.取出最大值 最小值 来判断
            while(!st.empty()){
                long long max_num=*st.rbegin();
                long long min_num=*st.begin();
                if(max_num<=k*min_num)  break;
                //否则就需要删除
                st.erase(st.find(nums[left]));
                left++;
            }
            //更新最大值
            ans=max(ans,i-left+1);
        }
        return nums.size()-ans;
    }
};
//其实可以进一步的优化并且简化
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //先排序 将可以不连续的移除的逻辑转换为必须使用连续移除的逻辑
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int left=0,max_len=0;
        for(int i=0;i<nums.size();i++){
            while((long long)nums[i]>(long long)k*nums[left]){
                left++;
            }
            max_len=max(max_len,i-left+1);
        }
        return nums.size()-max_len;
    }
};
