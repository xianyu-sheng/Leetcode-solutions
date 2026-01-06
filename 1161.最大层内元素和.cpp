/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        /*
            解题思路：使用层序遍历，然后记录每一层的总和以及层号 如果小于当前最大的就不管
            大于直接跟新
            等于也不管
        */
        int max_sum=INT_MIN;
        int index=-1;
        int global_index=0;
        if(root==nullptr)   return 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            int sum=0;
            global_index++;
            while(size--){
                //计算本层的总和
                TreeNode* cur=que.front();que.pop();
                sum+=cur->val;
                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            if(sum>max_sum){
                max_sum=sum;
                index=global_index;
            }
        }
        return index;
    }
};
// @lc code=end

