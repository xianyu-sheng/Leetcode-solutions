/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
            题意理解：注意解题细节即可，这个直接进行判断 直接将list2上的数据挂到list1
        */

        ListNode dummy(0);
        ListNode* tail=&dummy;
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        while(cur1!=nullptr && cur2!=nullptr ){
            if(cur2->val >= cur1->val){
                //先暂存cur1->next
                tail->next=cur1;
                cur1=cur1->next;
            }
            else{
                tail->next=cur2;
                cur2=cur2->next;
            }
            tail=tail->next;
        }
        tail->next=cur1?cur1:cur2;

        return dummy.next;
    }
};
// @lc code=end

