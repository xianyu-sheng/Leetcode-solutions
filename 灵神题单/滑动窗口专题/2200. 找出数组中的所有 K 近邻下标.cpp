//暴力法
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        
        // 对每个位置i，检查是否存在j满足条件
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[j] == key && abs(i - j) <= k) {
                    ans.push_back(i);
                    break;  // 找到一个j就够了
                }
            }
        }
        return ans;
    }
};
//滑动窗口思想
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int j = 0;  // 指向下一个key的位置
        
        for (int i = 0; i < n; i++) {
            // 移动j到第一个满足 |i-j|<=k 的key位置
            while (j < n && (nums[j] != key || abs(i - j) > k)) {
                // 如果j太远，需要前进
                if (j < i - k) {
                    j++;
                } else if (nums[j] != key) {
                    j++;
                } else {
                    break;
                }
            }
            
            // 检查是否找到满足条件的j
            if (j < n && nums[j] == key && abs(i - j) <= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
