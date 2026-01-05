/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* Creat(const vector<int>& nums,int left,int right){
        //出口条件
        if(left>right)  return nullptr;
        //然后开始构造
        int index=left+(right-left)/2;
        TreeNode* cur=new TreeNode(nums[index]);
        //然后开始构造后面的内容
        cur->left=Creat(nums,left,index-1);
        cur->right=Creat(nums,index+1,right);

        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*
            平衡二叉树  左右子树的差值不大于1 
            而这个数组是已经按升序排列的了 这里又是需要构造二叉搜索树
            二叉搜索树：根节点大于左子树节点 小于又子树节点 
            选择一个中间节点 然后每次二分选择一个根节点
        */
        return Creat(nums,0,nums.size()-1);
    }
};
// @lc code=end

