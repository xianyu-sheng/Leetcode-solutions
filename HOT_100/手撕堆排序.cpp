#include <iostream>
#include <vector>

using namespace std;

// 核心函数：维护最大堆的性质（下沉操作）
// arr: 存储堆的数组
// n: 当前堆的有效大小（注意：排序过程中 n 是不断缩小的）
// i: 当前需要进行“下沉”判断的节点下标
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // 默认当前节点 i 就是最大的
    int left = 2 * i + 1;   // 左孩子下标
    int right = 2 * i + 2;  // 右孩子下标

    // 如果左孩子存在，且比当前 largest 指向的值还要大，更新 largest
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右孩子存在，且比当前 largest 指向的值还要大，更新 largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是当前节点 i，说明它比孩子小，需要下沉交换
    if (largest != i) {
        swap(arr[i], arr[largest]); // 把最大的孩子换上来
        
        // 交换后，被换下去的那个节点可能会破坏它所在的子树的最大堆性质
        // 所以我们需要递归地对受影响的子树继续执行 heapify
        heapify(arr, n, largest);
    }
}

// 堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 步骤 1：建最大堆 (Build Max Heap)
    // 从最后一个非叶子节点开始往回遍历。最后一个非叶子节点的下标总是 (n / 2) - 1
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 步骤 2：依次取出堆顶最大元素，放到数组末尾，并重新维护堆
    for (int i = n - 1; i > 0; i--) {
        // 将当前堆顶（最大值）交换到堆的末尾 i 的位置
        swap(arr[0], arr[i]);
        
        // 此时，最大的元素已经排好序，不再参与后续调整。
        // 所以我们传入新的堆大小 i（相当于把末尾那个刚排好的元素踢出堆了）
        // 然后从堆顶（0号位置）开始重新下沉，恢复最大堆
        heapify(arr, i, 0); 
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "排序前: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "排序后: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

//空间复杂度为O(1)的方案 将下沉函数由递归改为迭代
// 迭代版下沉操作，空间复杂度优化至 O(1)
void heapifyIterative(vector<int>& arr, int n, int i) {
    // 使用循环不断向下探索，直到无法下沉为止
    while (true) {
        int largest = i;        // 默认当前节点最大
        int left = 2 * i + 1;   // 左孩子
        int right = 2 * i + 2;  // 右孩子

        // 找左右孩子中更大的那个
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // 如果 largest 没有变，说明当前节点已经比左右孩子都大了，符合最大堆性质
        if (largest == i) {
            break; // 停止下沉
        }

        // 否则，进行交换
        swap(arr[i], arr[largest]);
        
        // 更新当前关注的节点下标，在下一轮循环中继续考察它是否需要下沉
        i = largest; 
    }
}
