class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        /*
            因为这里nums[i]属于[-50,50]的区间 因此可以直接使用哈希表来进行记录每个数出现的评率 最后
            频率累计达到x的时候 就是找到了这个第x小的数
        */
        vector<int> ans;
        int cnt[101]={};
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]+50]++;
            if(i-k+1<0) continue;
            //在计数数组中找第x小
            int count=0;
            for(int j=0;j<101;j++){
                count+=cnt[j];
                if(count>=x){
                    ans.push_back(j-50<0 ? j-50:0);
                    break;
                }
            }
            //移除左端点
            cnt[nums[i-k+1]+50]--;
        }
        return ans;
    }
};
//灵神代码
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        constexpr int BIAS = 50;
        int cnt[BIAS * 2 + 1]{};
        for (int i = 0; i < k - 1; i++) { // 先往窗口内添加 k-1 个数
            cnt[nums[i] + BIAS]++;
        }

        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; i++) {
            cnt[nums[i] + BIAS]++; // 进入窗口（保证窗口有恰好 k 个数）
            int left = x; // 从 x 开始倒着减，减到 <= 0 就找到了答案
            for (int v = -50; v < 0; v++) { // 暴力枚举负数范围 [-50, -1]
                left -= cnt[v + BIAS];
                if (left <= 0) { // 找到答案
                    ans[i - k + 1] = v;
                    break;
                }
            }
            cnt[nums[i - k + 1] + BIAS]--; // 离开窗口
        }
        return ans;
    }
};
