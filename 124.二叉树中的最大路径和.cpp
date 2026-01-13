/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int max_sum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        // 1. 递归计算左右子节点的最大贡献
        // 如果贡献为负，我们宁愿不选（即取 0）
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 2. 当前节点作为“拐点”时的路径和
        int priceNewPath = node->val + leftGain + rightGain;

        // 3. 更新全局最大值
        max_sum = max(max_sum, priceNewPath);

        // 4. 返回节点的最大贡献值（只能选左右一侧，再加上节点自身）
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }
};
// @lc code=end

