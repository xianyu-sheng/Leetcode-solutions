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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //层序遍历---使用队列作为辅助
        vector<vector<int>> rel;
        if(root==nullptr)   return rel;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> cur_path;
            while(size--){
                TreeNode* cur=que.front();que.pop();
                cur_path.push_back(cur->val);
                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            rel.push_back(cur_path);
        }
        return rel;
    }
};