/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseList(ListNode* start,int k){
        ListNode* prev=nullptr;
        ListNode* curr=start;
        ListNode* next;

        for(int i=0;i<k;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
            题意理解：首先，创建一个虚拟头节点  然后创建一个尾指针  然后在创建一个快慢指针  慢指针在后面慢慢的翻转链表  快指针总是先提前的走到这一K区间的尾部 （或者是下一区间的头部）这个指针作用有二：第一，在慢指针进入下一个K区间进行翻转的时候，这里比如说是需要将新的尾指针创建在这里，第二，就是判断当前的剩余空间是不是能够满足K个节点的翻转
            整体伪代码流程为：
            创建虚拟头节点
            创建一个cur指针来看看到底走哪儿了  cur=&dummy
            创建fast  slow指针=head
            进入循环{
                创建tail指针=fast
                cur->next=tail;
                然后fast先走K步  判断能不能走完K步 如果可以走完 那么fast停在K+1的位置 然继续后面的翻转 如果不可以 那么直接退出循环  
                然后slow走一步  然后挂一个节点
            }
            返回dummy.next
        */

        if(!head  || !head->next  || k<=1)  return head;
        //创建虚拟头节点
        ListNode dummy(0);
        dummy.next=head;

        //创建快慢指针
        ListNode* cur=&dummy;   //当前组的前一个节点
        ListNode* slow=head;
        
        //开始循环
        while(true){
            int steps = 0;
            ListNode* fast = slow;
            while (fast && steps < k) {
                fast = fast->next;
                steps++;
            }
            if (steps < k) break;  // 不够 k 个，不翻转
            //这里说明就就还是可以翻转的 那么新建tail指针
            ListNode* tail=slow;    //这一组的尾部，翻转前的头
            ListNode* new_head=reverseList(slow,k);//返回翻转后的头

            //连接上一组以及下一组
            cur->next=new_head;
            tail->next=fast;
            //更新
            cur=tail;
            slow=fast;
        }
        return dummy.next;
    }
};
// @lc code=end

