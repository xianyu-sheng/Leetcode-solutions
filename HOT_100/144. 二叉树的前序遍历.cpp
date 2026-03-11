#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. 力扣标准的 TreeNode 结构体（必须保留）
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2. 核心递归函数（你的代码原封不动保留）
void prefs(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    ans.push_back(root->val);   // 根
    prefs(root->left, ans);     // 左
    prefs(root->right, ans);    // 右
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    prefs(root, ans);
    return ans;
}

//迭代法求前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //迭代法解题：中左右，对于每一个遍历到的数据 都是中 然后继续处理左子树 右子树
        vector<int> rel;
        if(root == NULL)
            return rel;
        stack<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            //先处理当前节点
            TreeNode* cur=que.top();
            que.pop();
            rel.push_back(cur->val);
            if(cur->right)
                que.push(cur->right);
            if(cur->left)
                que.push(cur->left);
        }
        return rel;
    }
};

//栈模拟前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rel;
        stack<TreeNode*> st;
        if(root)
            st.push(root);
        while(!st.empty())
        {
            //前序遍历：中左右，进栈顺序变为右左中
            TreeNode* cur=st.top();
            if(cur!=NULL)
            {
                //先弹出在压入右左中
                st.pop();
                if(cur->right)
                    st.push(cur->right);
                if(cur->left)
                    st.push(cur->left);
                st.push(cur);
                st.push(NULL);
            }
            else
            {
                //如果是NULL代表下一个节点就是我们要处理的节点
                st.pop();
                TreeNode* node=st.top();
                rel.push_back(node->val);
                st.pop();
            }
        }
        return rel;
    }
};


// 4. 辅助函数：层序建树（处理力扣输入数组，-1 代表 null）
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

// 5. main 函数：ACM 模式的核心（输入输出流程）
int main() {
    // 示例 1 输入：root = [1,null,2,3] → 对应数组 {1,-1,2,-1,-1,3,-1}
    vector<int> nums = {1, -1, 2, -1, -1, 3, -1};
    
    // 构建二叉树
    TreeNode* root = buildTree(nums);
    
    // 调用你写的前序遍历函数
    vector<int> result = preorderTraversal(root);
    
    // 输出结果（格式和力扣一致）
    cout << "[";
    for (int j = 0; j < result.size(); j++) {
        if (j > 0) cout << ",";
        cout << result[j];
    }
    cout << "]" << endl; // 输出：[1,2,3]
    
    return 0;
}
