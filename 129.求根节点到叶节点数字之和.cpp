/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int  dfs(TreeNode* root,int current_sum){
        if(root==nullptr)   return 0;
        current_sum=current_sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return current_sum;
        }
        return dfs(root->left,current_sum)+dfs(root->right,current_sum);
    }
    int sumNumbers(TreeNode* root) {
        /*
            解题思路：使用深度优先搜索，然后开两个vector数组 一个结果数组一个path数组 一直走到一个节点是叶子节点了
            然后不停地访问下一个节点

            但是这种方法态慢了 时间空间复杂度都很高 我门应该可以直接使用O(N)的方式来解决这个问题
            那就是直接dfs累加，由于我们这是递归的  因此对于每一次调用 它的每一层都会有自己的递归栈 那么就不需要考虑回溯的问题我认为 
        */
        return dfs(root,0);
    }
};
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
    vector<vector<int>> rel;
    vector<int> path;
    void  dfs(TreeNode* root){
        //终止条件  就当是已经遍历到了叶子节点的下一个节点了在终止把 那么我在进行分支的时候也不判断了
        if(root==nullptr)   return;
        path.push_back(root->val);
        //如果是已经是叶子节点了 那么就加入结果
        if(root->left==nullptr && root->right==nullptr){
            rel.push_back(path);
        }else{
            dfs(root->left);
            dfs(root->right);
        }
        //回溯 撤销本层选择
        path.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        /*
            解题思路：使用深度优先搜索，然后开两个vector数组 一个结果数组一个path数组 一直走到一个节点是叶子节点了
            然后不停地访问下一个节点
        */
        //然后向里面来加入root
        dfs(root);
        //然后我们得到了一个结果数组
        int sum=0;
        for(vector<int>& p : rel){
            int nums=0;
            for(auto num : p){
                nums=nums*10+num;
            }
            sum+=nums;
        }
        return sum;
    }
};
// @lc code=end

