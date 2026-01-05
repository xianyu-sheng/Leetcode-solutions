/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    void DFS(TreeNode* root,vector<int>& rel){
        if(root==nullptr)   return;
        DFS(root->left,rel);
        rel.push_back(root->val);
        DFS(root->right,rel);
    }
    bool isValidBST(TreeNode* root) {
        /*
            验证二叉搜索树-----将其中序遍历输出 判断是不是严格递增的 
            因为中序遍历的数组就是有序的
            中序遍历  左根右
        */
        vector<int> rel;
        DFS(root,rel);
        //然后来判断
        for(int i=0;i<rel.size()-1;i++){
            if(rel[i+1]<=rel[i]) return false;
        }
        return true;
    }
};
// @lc code=end

