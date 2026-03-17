//使用Fisher-Yates 洗牌算法 这是升成有线集合随机排列的算法
#include <vector>
#include <cstdlib>
#include <algorithm>

class Solution {
public:
    void shuffle(std::vector<int>& nums) {
        int n = nums.size();
        // 从后往前遍历
        for (int i = n - 1; i >= 0; i--) {
            // 在 [0, i] 范围内随机生成一个索引 j
            // 注意：rand() 产生的伪随机数在实际工程中有局限性，但在手撕算法中通常可接受
            int j = rand() % (i + 1); 
            
            // 交换 nums[i] 和 nums[j]
            std::swap(nums[i], nums[j]);
        }
    }
};
