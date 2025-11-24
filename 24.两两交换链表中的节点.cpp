/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /*
            两两进行交换---->就像之前提及到的一个K节点交换一个道理
        */
        ListNode dummyhead(0);
        ListNode* cur=&dummyhead;
        cur->next=head;
        if(cur->next==NULL || cur->next->next==NULL){
            return head;
        }
        while(cur->next!=NULL && cur->next->next!=NULL){
            //先暂存第一个节点
            ListNode* temp=cur->next;
            //然后让cur->next指向原本的第二个节点 让其变为第一个节点
            cur->next=temp->next;
            //第三步，让原本第二个节点的后一个节点指向原本的第一个节点的next
            temp->next=cur->next->next;
            //然后让原本的第二节点的next指向第一个节点
            cur->next->next=temp;
            //最后，让cur移项下一个需要交换的两个节点的前一个节点
            cur=temp;
        }
        return dummyhead.next;
    }
};
// @lc code=end

