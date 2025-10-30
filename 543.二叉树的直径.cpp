/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int  maxdiameter=0;
    int  backtrack(TreeNode* root){
        if(root==NULL) return 0;

        int left_num=backtrack(root->left);
        int right_num=backtrack(root->right);

        //当前节点的处理
        int curr_nums=left_num+right_num;
        maxdiameter=max(curr_nums,maxdiameter);

        return max(left_num,right_num)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        /*
            题意理解：能够看见的是  这里其实就是求左子树的最深边长  以及 右子树的最深边长  他们的总边长
            使用递归来完成这个题  使用先序遍历 
        */
        backtrack(root);

        return maxdiameter;
    }
};
// @lc code=end

