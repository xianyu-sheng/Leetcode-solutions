#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)   return nums.size();
        vector<int> dp(nums.size(),1);
        int max_length=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>max_length)    max_length=dp[i];
        }
        return max_length;
    }
};
//灵神代码，贪心+二分查找
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for (int x : nums) {
            auto it = ranges::lower_bound(g, x);
            if (it == g.end()) {
                g.push_back(x); // >=x 的 g[j] 不存在
            } else {
                *it = x;
            }
        }
        return g.size();
    }
};


int main() {
    // 策略：先读入数组长度，再读入元素（最简健壮写法）
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        
        Solution sol;
        int res = sol.maxSubArray(nums);
        cout << res << endl;
    }
    return 0;
}
