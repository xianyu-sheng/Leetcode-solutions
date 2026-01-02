/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
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
    TreeNode* invertTree(TreeNode* root) {
        /*
            这里的翻转二叉树其实就是，对于每一个节点，他的左右孩子节点交换位置
            然后在进行比如深度遍历啊 这样的操作  然后在每个节点都这样做
        */
        if(root==nullptr)   return nullptr;
        //然后先交换当前的左右孩子节点
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        //然后开始深度遍历左右孩子节点
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
// @lc code=end

