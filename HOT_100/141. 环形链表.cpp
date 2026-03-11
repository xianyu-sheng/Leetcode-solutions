#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 增强版：支持建环的 buildList
// pos 为环入口在数组中的下标，-1 表示无环
ListNode* buildListWithCycle(const vector<int>& nums, int pos) {
    if (nums.empty()) return nullptr;
    
    ListNode dummy(0);
    ListNode* curr = &dummy;
    ListNode* cycleEntry = nullptr; // 记录环入口
    ListNode* tail = nullptr;

    for (int i = 0; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
        if (i == pos) {
            cycleEntry = curr; // 记录第 pos 个节点
        }
        if (i == nums.size() - 1) {
            tail = curr; // 记录尾节点
        }
    }

    // 如果 pos 有效，手动闭合环
    if (cycleEntry && tail) {
        tail->next = cycleEntry;
    }

    return dummy.next;
}

// 核心逻辑：力扣 141. 环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // 模拟输入：数组长度 n，数组元素，环的位置 pos
    int n, pos;
    while (cin >> n >> pos) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        ListNode* head = buildListWithCycle(nums, pos);
        
        Solution sol;
        bool res = sol.hasCycle(head);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
