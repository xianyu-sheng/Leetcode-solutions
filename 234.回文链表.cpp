/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* reverseList(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        /*
            题意理解：需要使用O（n）的时间复杂度以及O（1）的时间复杂度
            应该怎样来解题？----->当然最笨的办法就是将这些节点的数据全部收集起来串成一个字符串  然后进行经典的字符串的回文判断
            使用快慢指针找中点，然后在将后半部分链表进行反转  然后在进行比较

        */
        if(!head  || !head->next)   return true;

        //使用快慢指针找打中点
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //找到中点然后进行反转链表
         ListNode* second_half = reverseList(slow->next);
         //比较前半部分和反转后的后半部分
        ListNode* first_half=head;
        ListNode* second_half_temp=second_half;
        bool  rel=true;
        while(second_half_temp!=nullptr){
            if(first_half->val!=second_half_temp->val){
                rel=false;
                break;
            }
            first_half=first_half->next;
            second_half_temp=second_half_temp->next;
        }
        return rel;
    }
};
// @lc code=end

