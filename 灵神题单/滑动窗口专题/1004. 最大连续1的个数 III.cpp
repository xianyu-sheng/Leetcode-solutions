class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*
           与之前的思路一样 
        */
        int count_0=0,count_1=0;
        int ans=0;
        for(int l=0,r=0;r<nums.size();r++){
            count_0+=(nums[r]==0);
            count_1+=(nums[r]==1);
            while(count_0>k){
                count_0-=(nums[l]==0);
                count_1-=(nums[l]==1);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

//灵神代码
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0, cnt0 = 0;
        for (int right = 0; right < nums.size(); right++) {
            cnt0 += 1 - nums[right]; // 0 变成 1，用来统计 cnt0
            while (cnt0 > k) {
                cnt0 -= 1 - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
