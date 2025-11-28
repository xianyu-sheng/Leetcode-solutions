/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> list_node;
    void middle_search(TreeNode* root){
        //终止条件 如果是空节点那么就退出
        if(root==nullptr)   return;
        //根左右
        middle_search(root->left);
        list_node.push_back(root);
        middle_search(root->right);
    }
    TreeNode* buildBlance(int left,int right){
        if(left > right)    return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* root=list_node[mid];
        root->left=buildBlance(left,mid-1);
        root->right=buildBlance(mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        /*
            解题思路：二叉搜索树变平衡二叉搜索树  平衡二叉搜索树--- 左右子树的高度差不超过1  同时满足二叉树的性质 根节点大于左子树节点 小于又子树的节点
            我想使用一个数组先将这些节点给记录起来  使用一个有序数组来进行记录 然后通过类似二分查找的逻辑 不断的去求中件的mid当做目前的子树的根节点
            然后左边的节点就是左子树 右边的节点就是右子树 那么就使用中序遍历嘛  二叉搜索树加中序遍历 天然有序
        */

        //1.先将有序数组做出来
        middle_search(root);
        //2.然后就是构造平衡二叉树 这里需要注意的是 在新的二叉树中 当left==right的时候 应该是需要将左右指针都置为nullptr
        return buildBlance(0,list_node.size()-1);
    }
};