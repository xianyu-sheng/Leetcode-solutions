/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        /*
            解题思路：首先，可以先将每一个节点以及他的下一个节点通过一个map数组存储起来  然后在一个个的将其取出来
            我们需要维持他们之间的关系吗？ 我感觉似乎不需要
        */
        multimap<int,ListNode*>  map_1;
        ListNode dummy(0);
        ListNode* curr=head;
        while(curr){
            map_1.insert({curr->val,curr});
            curr=curr->next;
        }
        //然后开始重新将这个新的节点顺序链接成链表 链接上这个dummyhead
        curr=&dummy;
        for(auto& p : map_1){
            curr->next=p.second;
            curr=curr->next;
        }
        curr->next=nullptr;//这里对于最后一个元素也应该需要手动处理 否则 最后一个元素可能还是会指向之前的节点 造成环形列表的现象
        return dummy.next;
    }
};
// @lc code=end

