//灵神代码
class Solution {
    // 在子数组 [left, right] 中随机选择一个基准元素 pivot
    // 根据 pivot 重新排列子数组 [left, right]
    // 重新排列后，<= pivot 的元素都在 pivot 的左侧，>= pivot 的元素都在 pivot 的右侧
    // 返回 pivot 在重新排列后的 nums 中的下标
    // 特别地，如果子数组的所有元素都等于 pivot，我们会返回子数组的中心下标，避免退化
    int partition(vector<int>& nums, int left, int right) {
        // 1. 在子数组 [left, right] 中随机选择一个基准元素 pivot
        int i = left + rand() % (right - left + 1);
        int pivot = nums[i];
        // 把 pivot 与子数组第一个元素交换，避免 pivot 干扰后续划分，从而简化实现逻辑
        swap(nums[i], nums[left]);

        // 2. 相向双指针遍历子数组 [left + 1, right]
        // 循环不变量：在循环过程中，子数组的数据分布始终如下图
        // [ pivot | <=pivot | 尚未遍历 | >=pivot ]
        //   ^                 ^     ^         ^
        //   left              i     j         right

        i = left + 1;
        int j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            // 此时 nums[i] >= pivot

            while (i <= j && nums[j] > pivot) {
                j--;
            }
            // 此时 nums[j] <= pivot

            if (i >= j) {
                break;
            }

            // 维持循环不变量
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // 循环结束后
        // [ pivot | <=pivot | >=pivot ]
        //   ^             ^   ^     ^
        //   left          j   i     right

        // 3. 把 pivot 与 nums[j] 交换，完成划分（partition）
        // 为什么与 j 交换？
        // 如果与 i 交换，可能会出现 i = right + 1 的情况，已经下标越界了，无法交换
        // 另一个原因是如果 nums[i] > pivot，交换会导致一个大于 pivot 的数出现在子数组最左边，不是有效划分
        // 与 j 交换，即使 j = left，交换也不会出错
        swap(nums[left], nums[j]);

        // 交换后
        // [ <=pivot | pivot | >=pivot ]
        //               ^
        //               j

        // 返回 pivot 的下标
        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        int target_index = n - k; // 第 k 大元素在升序数组中的下标是 n - k
        int left = 0, right = n - 1; // 闭区间
        while (true) {
            int i = partition(nums, left, right);
            if (i == target_index) {
                // 找到第 k 大元素
                return nums[i];
            }
            if (i > target_index) {
                // 第 k 大元素在 [left, i - 1] 中
                right = i - 1;
            } else {
                // 第 k 大元素在 [i + 1, right] 中
                left = i + 1;
            }
        }
    }
};
