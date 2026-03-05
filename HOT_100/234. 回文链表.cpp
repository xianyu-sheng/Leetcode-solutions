/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//快慢指针法找中点进行翻转
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        //1.创建虚拟头结点
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        //快慢指针来找中电 进行翻转
        ListNode* slow=dummy;
        ListNode* fast=dummy;

        //循环找中电
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //统一翻转后半段 slow->next
        ListNode* cur=slow->next;
        ListNode* pre=nullptr;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;cur=temp;
        }
        //pre是后半段的起点
        slow=head;
        bool ispal=true;
        while(pre){
            if(pre->val!=slow->val){
                ispal=false;
                break;
            }
            slow=slow->next;
            pre=pre->next;
        }
        delete dummy;
        return ispal;
    }
};
//利用栈的后进先出的性质来进行解答
#include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        std::stack<int> s;

        // 第一阶段：快慢指针移动，慢指针值入栈
        while (fast && fast->next) {
            s.push(slow->val); // 边走边存
            slow = slow->next;
            fast = fast->next->next;
        }

        // 第二阶段：根据快指针状态判断奇偶
        // 如果 fast != nullptr，说明是奇数长度，fast 停在最后一个节点
        // 此时 slow 停在正中间，中间的数不用比，slow 向前走一步
        if (fast != nullptr) {
            slow = slow->next;
        }
        // 如果 fast == nullptr，说明是偶数长度
        // 此时 slow 停在下半段第一个节点，直接开始比

        // 第三阶段：继续遍历慢指针，并与栈顶元素比较
        while (slow) {
            if (s.empty()) return false; // 理论上不会发生，除非逻辑错误
            if (slow->val != s.top()) {
                return false;
            }
            s.pop();
            slow = slow->next;
        }

        // 最后检查栈是否为空（理论上如果是回文，这里一定是空的）
        return s.empty();
    }
};
