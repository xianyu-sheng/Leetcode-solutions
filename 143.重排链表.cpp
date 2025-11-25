/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        /*
            解题思路：将这些个节点存储在一个vector数组中，然后使用一前一后两个指针向中间压缩
        */
        ListNode* cur=head;
        if(!cur || !cur->next)  return;
        vector<ListNode*>  ListNode_vec;
        //开始遍历
        while(cur){
            ListNode_vec.push_back(cur);
            cur=cur->next;
        }
        //然后开始一前一后开始往上挂节点
        ListNode dummyhead(0);
        cur=&dummyhead;
        //然后开始挂节点
        int l=0,r=ListNode_vec.size()-1;
        while(l<=r){
            cur->next=ListNode_vec[l];
            cur=cur->next;
            cur->next=ListNode_vec[r];
            cur=cur->next;
            l++;r--;
        }
        cur->next=nullptr;
    }
};
// @lc code=end

