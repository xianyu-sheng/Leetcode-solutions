/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    vector<TreeNode*> table;
    void pre(TreeNode* root){
        if(root==nullptr)    return;
        //中左右
        table.push_back(root);
        pre(root->left);
        pre(root->right);
    }
    void flatten(TreeNode* root) {
        /*
            题目理解：先序遍历，中左右  那我们是否可以这样就是先将二叉树按照先序遍历将其摘下来，然后在串起来
        */
        pre(root);
        TreeNode Pre(0);
        TreeNode* pre_cur=&Pre;
        for(int i=0;i<table.size();i++){
            pre_cur->right=table[i];
            table[i]->left=nullptr;
            pre_cur=table[i];
        }
    }
};
// @lc code=end

