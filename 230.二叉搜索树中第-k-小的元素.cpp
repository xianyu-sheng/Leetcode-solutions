/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int count=0;
    int relult=0;
    void pre(TreeNode* root,int k){
        if(root==nullptr)   return;
        pre(root->left,k);
        count++;
        if(count==k){
            relult=root->val;
            return;
        }
        pre(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        /*
            题目理解：我认为可以使用一个单调栈来进行遍历   首先我们需要明确单调栈的顺序 是从小到大还是从大到小（从栈顶到栈底）我认为我门既然是要求第k小的元素 那么可以维护一个从大道小的栈 那么到时候我们的栈顶就是第k小的元素 那么我们该如何进行编码呢  应该是一个什么思路  当我们遍历到的节点小于栈顶元素的时候我们就弹出栈顶元素然后将更小的元素放进去 不过这样不好 我认为最后的极端情况可能是栈中只有一个节点的元素  即最小的元素 
            那么我们应该如何来做呢？  首先这是一颗二叉搜索树 那么这个树就是有顺序的  其中根节点大于左子树的节点 小于右子树的节点
            最笨的办法当然是将所有的元素全部取出来 然后排序  但是我认为这是最笨的办法 我们应该能够利用二叉搜索树的性质
            不过我不知道应该怎样来利用 我想先使用先序遍历然后将数据取出来 先使用最笨的办法 解题
        二叉搜索树的中序遍历就是升序
        */
        pre(root,k);
        return relult;
    }
};
// @lc code=end

