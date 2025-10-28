/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
            什么是深拷贝？-->将带拷贝的位置上的所有内容都单独领出来一份给新的位置
            对原始数据我们不进行修改  只是每一次传入一个节点进行更新
            tail_node 代表需要挂上的尾巴 new_node  代表这次需要加入的新的节点
        */
        //如果链表为空那么就直接返回nullptr
        if(!head)   return nullptr;

        //第一步，创建一个map  并用原节点映射到新节点
        unordered_map<Node*,Node*> old_to_new;
        Node* curr=head;
        while(curr){
            old_to_new[curr]=new Node(curr->val);//创建一个新节点 将其作为原链表的当前节点的值
            curr=curr->next;
        }
        //然后开始设置next和random指针
        curr=head;
        while(curr){
            Node*  new_node=old_to_new[curr];   //取出新建链表节点【也就是目前原节点对应的新建的那一个节点】
            new_node->next=old_to_new[curr->next];//新节点指向的next节点  应该是原链表的旧节点的next指向的节点的新值 这样才不会新的节点next指向的值仍然是旧链表中的节点
            new_node->random=old_to_new[curr->random];//random的指向这里与上面同理
            curr=curr->next;
        }
        return old_to_new[head]; 
    }
};
// @lc code=end

