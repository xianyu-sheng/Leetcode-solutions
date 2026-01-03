/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

 //方法1：深度遍历
class Solution {
public:
    bool  check(TreeNode* p,TreeNode* q){
        //1.两个都为空 那么就返回true
        if(!p && !q)    return true;
        //2.只有一个为空 或者是值不一样
        if(!p || !q || p->val!=q->val)  return false;

        //继续递归
        return check(p->left,q->right) && check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        /*
            什么是轴对称 翻过来一样嘛
            那我直接使用一个双端队列 然后每次网里面push元素 然后左边的比较左子树？右边的比较右子树吗？好像也不太对
        */
        if(!root)   return true;

        return check(root->left,root->right);
    }
};
//方法2：层序
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        // 使用普通队列即可，每次处理两个
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            // 每次取出两个节点进行比较
            TreeNode* u = q.front(); q.pop();
            TreeNode* v = q.front(); q.pop();
            
            // 逻辑与递归的 Base Case 一样
            if (!u && !v) continue; // 都是空，通过，继续看下一对
            if (!u || !v || (u->val != v->val)) return false; // 不对称
            
            // 将子节点按“镜像”顺序入队
            // 1. 比较 u的左 和 v的右 (外侧)
            q.push(u->left);
            q.push(v->right);
            
            // 2. 比较 u的右 和 v的左 (内侧)
            q.push(u->right);
            q.push(v->left);
        }
        
        return true;
    }
};
// @lc code=end

