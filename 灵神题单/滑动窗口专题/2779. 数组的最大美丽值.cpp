class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //这里我们要求数组的最大美丽值  他是这样定义的，每次可以选择此前没有选过的i来进行替换 那么 那不就是从0-n-1的遍历吗 这样每一个i都只会选择一次 并且每一次都是新选择的  然后替换为[nums[i] - k, nums[i] + k]这个窗口内的任一整数 那么我认为这里结合美丽值的定义 我认为这里就是去求这个区间内的频率最高的值 然后将其替换就行
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int l=0,r=0;r<nums.size();r++){
            while(nums[r]-nums[l]>2*k){
                //说明此时nums[l]太小了 移动
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

//我原本的思路的解题代码
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // 1. 找到数组中的最大值，用来确定我们需要多大的“数轴”（差分数组的长度）
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }
        
        // 2. 初始化差分数组
        // 按照我们刚才讨论的平移技巧，区间变成了 [nums[i], nums[i] + 2 * k]
        // 所以数轴的最大可能位置是 max_val + 2 * k
        // 差分数组需要在终点的后一位执行减操作，所以数组大小需要再加 2
        int max_bound = max_val + 2 * k + 2; 
        vector<int> diff(max_bound, 0);
        
        // 3. 核心：实现你的想法——把每个元素转化为区间，并记录频率的变化
        for (int num : nums) {
            // 区间起点频率 +1
            diff[num]++; 
            // 区间终点后一位频率 -1 (表示过了这个区间，重叠数就减少了)
            diff[num + 2 * k + 1]--; 
        }
        
        // 4. 从头到尾扫描数轴，找出“频率最高”的那个值（最大美丽值）
        int max_beauty = 0;
        int current_freq = 0; // 记录当前点被多少个区间覆盖（当前频率）
        
        for (int i = 0; i < max_bound; ++i) {
            // 前缀和累加，还原出当前位置的真实覆盖频率
            current_freq += diff[i]; 
            // 挑战历史最高频率
            max_beauty = max(max_beauty, current_freq); 
        }
        
        return max_beauty;
    }
};
