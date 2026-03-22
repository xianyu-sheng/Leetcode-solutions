#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        // 定义dp：key=异或值，value=能得到该值的【最长】子序列长度
        unordered_map<int, int> dp;
        // 初始状态：空数组，异或和=0，长度=0（最基础的状态）
        dp[0] = 0;

        // 遍历数组里的每一个数字
        for (int num : nums) {
            // 必须复制一份旧的dp！防止遍历的时候被修改（新手必记）
            unordered_map<int, int> temp = dp;
            
            // 遍历旧dp里所有的异或结果
            for (auto& [xor_val, len] : temp) {
                // 新异或值 = 旧值 ^ 当前数字
                int new_xor = xor_val ^ num;
                // 新长度 = 旧长度 + 1
                int new_len = len + 1;

                // 如果新异或值没出现过，或者新长度更长 → 更新dp
                if (dp.find(new_xor) == dp.end() || new_len > dp[new_xor]) {
                    dp[new_xor] = new_len;
                }
            }
        }

        // 最后判断：能不能找到异或和=target的子序列
        if (dp.find(target) == dp.end()) {
            return -1; // 找不到，返回-1
        } else {
            // 最少删除数 = 总长度 - 最长合法子序列长度
            return nums.size() - dp[target];
        }
    }
};
