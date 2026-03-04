#include <iostream>
#include <vector>
using namespace std;

// 分区函数：返回基准值的最终索引
// 参数：待排序数组、左边界low、右边界high
int partition(vector<int>& arr, int low, int high) {
    // 选最右侧元素作为基准值
    int pivot = arr[high];
    // i：指向「小于基准值区域」的最后一个元素（初始为左边界前一位）
    int i = low - 1;

    // j遍历从low到high-1的所有元素
    for (int j = low; j < high; ++j) {
        // 如果当前元素小于等于基准值，划入左侧区域
        if (arr[j] <= pivot) {
            i++; // 左侧区域扩大
            swap(arr[i], arr[j]); // 交换当前元素到左侧区域
        }
    }

    // 把基准值放到最终位置（i+1）
    swap(arr[i + 1], arr[high]);
    return i + 1; // 返回基准值的索引
}

// 快速排序递归函数
void quickSort(vector<int>& arr, int low, int high) {
    // 递归终止条件：子数组长度<=1（low >= high）
    if (low < high) {
        // 分区，得到基准值的索引
        int pivotIndex = partition(arr, low, high);

        // 递归排序基准左侧子数组（low 到 pivotIndex-1）
        quickSort(arr, low, pivotIndex - 1);
        // 递归排序基准右侧子数组（pivotIndex+1 到 high）
        quickSort(arr, pivotIndex + 1, high);
    }
}

// 辅助函数：打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 主函数测试
int main() {
    // 测试用例
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "排序前数组：";
    printArray(arr);

    // 调用快速排序（左边界0，右边界arr.size()-1）
    quickSort(arr, 0, arr.size() - 1);

    cout << "排序后数组：";
    printArray(arr);

    return 0;
}
