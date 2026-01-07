/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 *
 * [1339] 分裂二叉树的最大乘积
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
    long long sum=0;
    long long mod=1e9+7;
    long long  rel=INT_MIN;
    void DFS(TreeNode* root){
        if(root==nullptr)   return;
        sum+=root->val;
        DFS(root->left);
        DFS(root->right);
    }
    long long PostFS(TreeNode* root){
        //从叶子节点层开始计算 然后统计每一个节点作为根节点时的最大乘积
        if(root==nullptr)   return 0;
        long long sub_sum=0;
        //使用后续遍历
        long long left=PostFS(root->left);
        long long right=PostFS(root->right);
        sub_sum+=(left+right+root->val);
        rel=max(rel,sub_sum*(sum-sub_sum));
        return sub_sum;
    }
    int maxProduct(TreeNode* root) {
        /*
            分裂二叉树的最大乘积
            将其通过中序遍历得出全部的有序序列 然后选择中位数来分割两侧 最后返回乘积

            不不 应该选择分裂的点是 两侧的和接近的时候  这个时候我们需要的是 就是先统计出来所有元素的和 然后在统计较小的一侧
            然后另外一层就是相减  统计所有可能的子树和在 然后动态的进行更新最大可能的乘积值
            
        */
        DFS(root);
        //然后去找最接近一半的时候
        PostFS(root);
        return rel%mod;
    }
};
// @lc code=end

