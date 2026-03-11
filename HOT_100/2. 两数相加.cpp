#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

// 构建链表（核心逻辑不变）
ListNode* buildList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

// 两数相加（核心逻辑不变）
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int l1_num = l1 ? l1->val : 0;
        int l2_num = l2 ? l2->val : 0;
        int sum = l1_num + l2_num + carry;
        
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carry = sum / 10;
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}

// 极简main函数：输入→计算→输出
int main() {
    vector<int> num1, num2;
    int x;

    // 输入第一个链表（输入数字，按回车+Ctrl+Z(Windows)/Ctrl+D(Linux)结束）
    while (cin >> x) num1.push_back(x);
    cin.clear(); // 重置cin状态，避免影响后续输入
    cin.ignore();// 忽略换行符

    // 输入第二个链表
    while (cin >> x) num2.push_back(x);

    // 构建链表+计算+输出
    ListNode* l1 = buildList(num1);
    ListNode* l2 = buildList(num2);
    ListNode* res = addTwoNumbers(l1, l2);
    
    for (ListNode* p = res; p; p = p->next) cout << p->val << " ";
    
    return 0;
}
