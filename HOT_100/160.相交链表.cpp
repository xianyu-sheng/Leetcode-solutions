#include <iostream>

using namespace std;

// 1. 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. 核心算法类 (直接复制你的代码)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }

        return curA;
    }
};

// 3. 辅助函数：快速用数组建链表并返回头节点和尾节点
// 这里用引用参数返回尾节点，方便后续拼接
ListNode* buildList(int len, ListNode*& tail) {
    if (len == 0) {
        tail = nullptr;
        return nullptr;
    }
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* cur = head;
    for (int i = 1; i < len; ++i) {
        cin >> val;
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    tail = cur; // 记录尾节点
    return head;
}

// 4. Main 函数：极简 I/O 和 链表拼接
int main() {
    int lenA, lenB, lenC;
    
    // 一直读取测试用例，直到没有输入
    while (cin >> lenA >> lenB >> lenC) {
        ListNode *tailA = nullptr, *tailB = nullptr, *tailC = nullptr;

        // 分别构建三段链表
        ListNode* partA = buildList(lenA, tailA);
        ListNode* partB = buildList(lenB, tailB);
        ListNode* commonC = buildList(lenC, tailC);

        // --- 核心动作：在内存中将它们拼接起来 ---
        // 将 A 的独立部分尾部连到公共部分
        ListNode* headA = partA ? partA : commonC;
        if (tailA) tailA->next = commonC;

        // 将 B 的独立部分尾部连到公共部分
        ListNode* headB = partB ? partB : commonC;
        if (tailB) tailB->next = commonC;

        // 调用算法测试结果
        Solution sol;
        ListNode* ans = sol.getIntersectionNode(headA, headB);

        // 输出结果
        if (ans) {
            cout << "相交节点的值为: " << ans->val << endl;
        } else {
            cout << "不相交 (null)" << endl;
        }
    }

    return 0;
}
