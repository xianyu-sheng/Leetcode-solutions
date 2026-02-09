class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //我们是不是可以这样先计算出所有的1的个数 然后以这个个数来当做滑动窗口 然后来选择空缺1的位置最少的窗口
        int width=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            width+=(nums[i]==1?1:0);
        }
        if(width==0 || width==n)    return 0;
        //然后我们以此来当做窗口 然后来移动
        int ans=INT_MAX;
        int zero_sum=0;
        for(int i=0;i<n+width-1;i++){
            if(nums[i%n]==0)  zero_sum+=1;
            if(i-width+1<0) continue;
            //然后现在是够一个窗口了 然后来计算交换次数
            ans=min(ans,zero_sum);
            //然后将最左边的0去掉
            if(nums[(i-width+1)%n]==0)  zero_sum-=1;
        }
        return ans;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = reduce(nums.begin(), nums.end(), 0); // 1 的个数
        if (k == 0) { // 没有 1，无需交换
            return 0;
        }

        int n = nums.size();
        int max1 = 0, cnt1 = 0;
        for (int i = 0; i < n + k - 1; i++) {
            // 1. 进入窗口
            cnt1 += nums[i % n];
            if (i < k - 1) { // 窗口大小不足 k
                continue;
            }
            // 2. 更新答案
            max1 = max(max1, cnt1);
            // 3. 离开窗口，为下一个循环做准备
            cnt1 -= nums[i - k + 1]; // 由于我们保证 i < n+k-1，所以 i-k+1 < n，无需取模
        }
        return k - max1;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii/solutions/1200295/duan-huan-cheng-lian-hua-dong-chuang-kou-ws80/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
