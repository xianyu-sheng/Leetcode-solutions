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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //逆序存储 那么如果就是前一位加起来大于0了 那么后一位就会加1
        //那么必须用一个数来存储进位  如果进位那位数等于0  那么就需要再后一位+1  如果最后的进位+1  那么在链表的最后还需要再加一个链表 连到后面  因此这里可以使用一个虚拟头结点来进行链表的维护以及更新
        ListNode* dummy_node=new  ListNode(0);
        ListNode* cur=dummy_node;
        int up_num=0;
        while(l1!=NULL  || l2!=NULL  || up_num!=0){
            //为什要这样来设计这个while循环呢？这里考虑的是三种情况其实，1.l1链表比l2长 2.l2链表可能比l1长 3.当遍历到两个链表的结尾了，还有进位时  这时候需要新建一个节点存储最后的进位
            int l1_num=(l1!=NULL)?l1->val:0;
            int l2_num=(l2!=NULL)?l2->val:0;

            int  sum=l1_num+l2_num+up_num;
            up_num=sum/10;
            sum=sum%10;

            cur->next=new ListNode(sum);
            cur=cur->next;

            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        return  dummy_node->next;
    }
};
