/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        /*
            层序遍历 如果该层的元素个数大于1  那么就输出最后一个
            反正就是输出最后一个元素
        */
        vector<int> rel;
        if(root==nullptr)   return rel;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* cur=que.front();que.pop();
                if(i==size-1)   rel.push_back(cur->val);
                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
        }
        return rel;
    }
};
// @lc code=end

