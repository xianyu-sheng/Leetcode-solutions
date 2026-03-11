#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数：层序数组转二叉树 (-1 代表 null)
TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // 左子节点
        if (nums[i] != -1) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;
        
        // 右子节点
        if (i < nums.size() && nums[i] != -1) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

//我的开始解法：自顶向下，存在大量的重复计算
class Solution {
public:
    int computedepth(TreeNode* tree)
    {
        if(tree==NULL)
            return 0;
        return 1+max(computedepth(tree->left),computedepth(tree->right));
    }
    bool isBalanced(TreeNode* root) {
        //什么是平衡二叉树？  每颗子树深度差值绝对值不超过1
        //分别计算左右子树的高度 然后判断差值
        if(root==NULL)
            return true;
        int leftcount=computedepth(root->left);
        int rightcount=computedepth(root->right);
        if(abs(leftcount-rightcount)>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

//灵神解法，标准解法，使用后序遍历 自低向上
class Solution {
    int get_height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1) {
            return -1;
        }
        return max(left_h, right_h) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        
        TreeNode* root = buildTree(nums);
        Solution sol;
        // 执行并打印结果...
    }
    return 0;
}
