/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法1：双指针相交法  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            题意理解：如何判定两个链表相交？高效的判定呢？以及如何在O（m+n）的时间复杂度内完成这项工作，怎样来做呢？我知道可以使用双指针来进行遍历，但是在相交点之前，他们各自都有几个节点才到橡胶节点呢？
            难道先计算出两个链表各自的长度  然后来进行一起遍历吗  这样的话应可以
            还有一种方法就是  假设链表A的长度为A  链表B的长度为B  公共部分为L  那么他们各自的部分为A-L  B-L  而如果cur_A将链表A遍历完成之后，再去遍历B-L  cur_B 也是一样 那么最后他们走的就都是A+B-L  这样如果有交点那么就能铁定碰见
        */
        if (!headA || !headB) return nullptr;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != curB) {
            // 如果 curA 走到末尾，就跳到 headB
            curA = curA ? curA->next : headB;

            // 如果 curB 走到末尾，就跳到 headA
            curB = curB ? curB->next : headA;
        }

        // 要么相遇于交点，要么相遇于 nullptr（不相交）
        return curA;
    }
};
//方法2：先长度计算再对齐在查看是否相交
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            题意理解：如何判定两个链表相交？高效的判定呢？以及如何在O（m+n）的时间复杂度内完成这项工作，怎样来做呢？我知道可以使用双指针来进行遍历，但是在相交点之前，他们各自都有几个节点才到橡胶节点呢？
            难道先计算出两个链表各自的长度  然后来进行一起遍历吗  这样的话应可以
        */
        if (!headA || !headB) return nullptr;
        unsigned int length_A=0;
        unsigned int length_B=0;
        ListNode* cur_A=headA;
        ListNode* cur_B=headB;
        while(cur_A!=NULL){
            length_A++;
            cur_A=cur_A->next;
        }
        while(cur_B!=NULL){
            length_B++;
            cur_B=cur_B->next;
        }
        cur_A=headA;
        cur_B=headB;
        if(length_A>length_B){
            for (int i = 0; i < length_A - length_B; ++i) {
                cur_A = cur_A->next;
            }
        }
        else{
             for (int i = 0; i < length_B - length_A; ++i) {
                cur_B = cur_B->next;
            }
        }
        while(cur_A!=NULL  && cur_B!=NULL){
            if(cur_A==cur_B){
                return cur_A;
            }
            cur_A=cur_A->next;
            cur_B=cur_B->next;
        }
        return NULL;
    }
};
// @lc code=end

