/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

 //方法1：深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        /*
            这里如果用广度优先搜素的话，那么就需要额外开辟一个队列来存储节点
            那我用深度优先搜索应该怎样？将每个遍历到的节点走当做新节点，然后
            返回最大的深度
        */
        if(root==nullptr)   return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        //返回左右子树中，较深的那棵子树
        return 1+max(left,right);
    }
};
//方法2：广度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //记录二叉树的最大深度 最简单的方法那么就是看其层序遍历的次数
        int count=0;
        if(root==NULL)
            return count;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();

            while(size--)
            {
                TreeNode* cur=que.front();
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            count++;
        }
        return count;
    }
};
// @lc code=end

