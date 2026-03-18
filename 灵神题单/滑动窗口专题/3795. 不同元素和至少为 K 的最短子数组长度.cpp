class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        /*
            第一，需要值是不同的
            第二，和至少为k
            那么这里就隐含一个问题就是如果left--right此时的和大于等于k  那么我们就可以尝试左移这个Left指针
            不断的去尝试最小的长度

            这里就需要两个条件都需要移动 第一，如果一个元素的频次大于1 第二 此时满足k 我们尝试继续缩小窗口
        */
        unordered_map<int,int> mymap;
        int ans=INT_MAX;
        long long curr_sum=0;//最短的值，以及当前的这个窗口的值大小
        for(int l=0,r=0;r<nums.size();r++){
            //1.入窗口
            if(mymap[nums[r]]==0){
                curr_sum+=nums[r];
            }
            mymap[nums[r]]++;
            while(curr_sum>=k){
                ans=min(ans,r-l+1);
                mymap[nums[l]]--;
                if(mymap[nums[l]]==0){
                    curr_sum-=nums[l];
                }
                l++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


//数组哈希
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        // 假设 nums[i] 的最大值为 10^5，我们开辟一个稍微大一点的数组即可
        // 全部初始化为 0，用来记录每个元素在窗口内出现的频次
        vector<int> cnt(100005, 0); 
        
        long long curr_sum = 0; 
        int ans = INT_MAX;

        for (int l = 0, r = 0; r < nums.size(); r++) {
            // 1. 进窗口：用数组做判断，速度极快
            if (cnt[nums[r]] == 0) {
                curr_sum += nums[r];
            }
            cnt[nums[r]]++; 

            // 2. 满足条件，记录并尝试缩小窗口
            while (curr_sum >= k) {
                ans = min(ans, r - l + 1); 

                // 3. 出窗口
                cnt[nums[l]]--; 
                
                if (cnt[nums[l]] == 0) {
                    curr_sum -= nums[l];
                }
                l++; 
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
