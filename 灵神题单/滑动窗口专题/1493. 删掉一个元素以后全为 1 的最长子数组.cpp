//我的解题思路
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //删掉一个元素以后全为1的最长子数组 那么题中还没有要求必须要连续的情况 这又是二进制字符串
        //那么就可以设计一个只有两个空的数组 然后来统计0 1 只要0保持<=1 那么就继续扩展 如果大于1 那么就移动左端点
        int cnt[2]{},left=0,ans=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            cnt[a]++;
            while(cnt[0]>1){
                //就需要移动左端点
                cnt[nums[left]]--;
                left++;
            }
            ans=max(ans,cnt[1]);
        }
        return cnt[1]==nums.size()?nums.size()-1:ans;
    }
};
//灵神代码解题思路
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, cnt0 = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 1. 入，nums[right] 进入窗口
            cnt0 += 1 - nums[right]; // 维护窗口中的 0 的个数
            while (cnt0 > 1) { // 不符合题目要求
                // 2. 出，nums[left] 离开窗口
                cnt0 -= 1 - nums[left]; // 维护窗口中的 0 的个数
                left++;
            }
            // 3. 更新答案，注意不是 right-left+1，因为我们要删掉一个数
            ans = max(ans, right - left);
        }
        return ans;
    }
};
