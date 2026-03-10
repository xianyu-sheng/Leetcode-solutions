#include <iostream>
#include <vector>

using namespace std;

// 1. 定义单链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. 你的核心算法原封不动搬过来
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};

// 3. 极简 Main 函数
int main() {
    int n;
    // 循环读取测试用例
    while (cin >> n) {
        if (n == 0) {
            // 处理空链表的情况，还需要吃掉输入流里的 pos (如果有的话，这里假设输入规范)
            int pos; cin >> pos; 
            cout << "false" << endl;
            continue;
        }

        // 读取所有节点值
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) {
            cin >> vals[i];
        }

        // 读取环的入口索引
        int pos;
        cin >> pos;

        // --- 核心动作：动态建链表并造环 ---
        ListNode* head = new ListNode(vals[0]);
        ListNode* cur = head;
        ListNode* cycleNode = (pos == 0) ? head : nullptr;

        for (int i = 1; i < n; ++i) {
            cur->next = new ListNode(vals[i]);
            cur = cur->next;
            // 记下应该形成环的那个节点
            if (i == pos) {
                cycleNode = cur;
            }
        }

        // 连上环！如果 pos != -1，就把尾巴指向 cycleNode
        if (pos != -1) {
            cur->next = cycleNode;
        }

        // 调用你的算法
        Solution sol;
        if (sol.hasCycle(head)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        
        // 注意：带环链表释放内存很麻烦，容易死循环。
        // 在 ACM 笔试中，只要程序能正常跑出结果，系统会统一回收进程内存，
        // 所以对于这种带环结构，通常直接 return 0 即可，不用强求 delete。
    }

    return 0;
}
