//1.头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1.头插法：使用一个虚拟头结点 对所有的节点都等同处理
        ListNode* dummy=new ListNode(0);
        ListNode* cur=head;
        //开始循环
        while(cur){
            //1.头插
            ListNode* temp=cur->next;
            cur->next=dummy->next;
            dummy->next=cur;
            cur=temp;
        }
        return dummy->next;
    }
};

//2.双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //还有一种方法就是使用双指针 类似于头插法 不断的从链表上摘节点下来 然后放到pre的前面
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};
