/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //使用层序遍历  这样自然的就会是这样 如果我不是最后一个元素 那么我就可以将下一个元素先top()出来 然后获得其
        //值 然后我们在继续下一步 如果已经是最后一个元素了 也就是弹出后在检查一次就行

        //使用一个队列容器来进行存储
        if(root==NULL)  return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            while(size--){
                Node* cur=que.front();que.pop();
                if(size==0) cur->next=NULL;
                else    cur->next=que.front();
                //然后将新的节点加入到que里面
                if(cur->left)   que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};
// @lc code=end

