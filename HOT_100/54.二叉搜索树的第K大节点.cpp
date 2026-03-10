/*
  核心就是二叉搜索树中序遍历是一个递增的序列，那么我们如果需要求出第K大最大节点 那么我们就需要右中左来遍历 确保遍历的结果是递减的一个序列 然后第K个节点就是我们要求的第K大节点
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 1. 节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 2. 核心算法 (跟前面完全一样)
class Solution {
private:
    int ans;   
    int count; 

    void traverse(TreeNode* root) {
        if (root == nullptr || count == 0) return;
        traverse(root->right);
        if (--count == 0) {
            ans = root->val;
            return;
        }
        traverse(root->left);
    }

public:
    int kthLargest(TreeNode* root, int k) {
        count = k;
        ans = -1; 
        traverse(root);
        return ans;
    }
};

// 3. 层序建树 (依然用队列，因为这是把数组转成树的唯一标准解法)
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // 左孩子
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // 右孩子
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// 4. 极简 Main 函数
int main() {
    int n;
    // 只要还有输入 n，就一直循环
    while (cin >> n) {
        vector<string> nodes(n);
        // 直接用一个简单的 for 循环读入所有节点
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
        }
        
        int k;
        // 读完树的节点，接下来读 k
        cin >> k;

        // 建树 -> 算结果 -> 打印
        TreeNode* root = buildTree(nodes);
        Solution sol;
        cout << sol.kthLargest(root, k) << endl;
    }

    return 0;
}

// 4. 黑科技 Main 函数
int main() {
    vector<string> nodes;
    string s;
    
    // 黑科技：一直读字符串，直到遇到换行符才跳出
    while (cin >> s) {
        nodes.push_back(s);
        // cin.get() 会读取紧跟在刚刚那个字符串后面的分隔符（空格或换行）
        if (cin.get() == '\n') {
            break; 
        }
    }
    
    // 如果没有读到任何节点，直接退出
    if (nodes.empty()) return 0;

    // 第二行：正常读取 k
    int k;
    cin >> k;

    // 建树 -> 算结果 -> 打印
    TreeNode* root = buildTree(nodes);
    Solution sol;
    cout << sol.kthLargest(root, k) << endl;

    return 0;
}
