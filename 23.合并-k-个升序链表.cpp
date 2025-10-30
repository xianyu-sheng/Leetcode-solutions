/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            第一，这里我认为还是需要通过一个map容器来进行帮助解决
            第一，这里里面会有相同的元素 那么我们应该使用mulitimap
        */
        multimap<int,ListNode*> mm;
        //然后开始遍历
        for(ListNode* head: lists){
            ListNode* curr=head;
            while(curr!=nullptr){
                mm.insert({curr->val,curr});
                curr=curr->next;
            }
        }
        //然后创建新链表
        ListNode dummy(0);
        ListNode* curr=&dummy;
        for(auto p:mm){
            curr->next=p.second;
            curr=curr->next;
        }
        curr->next=nullptr;
        return dummy.next;
    }
};
// @lc code=end

