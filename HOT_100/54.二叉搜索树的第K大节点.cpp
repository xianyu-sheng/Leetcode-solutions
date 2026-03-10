/*
  核心就是二叉搜索树中序遍历是一个递增的序列，那么我们如果需要求出第K大最大节点 那么我们就需要右中左来遍历 确保遍历的结果是递减的一个序列 然后第K个节点就是我们要求的第K大节点
*/


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// 1. 定义二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 2. 核心算法类
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
        ans = -1; // 初始化一个默认值
        traverse(root);
        return ans;
    }
};

// 3. 辅助函数：通过层序序列构建二叉树
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // 处理左子节点
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // 处理右子节点
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// 4. 辅助函数：释放二叉树内存 (防止内存泄漏，体现工程素养)
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 5. Main 函数：处理 ACM 格式的输入输出
int main() {
    string line;
    // 循环读取每一组用例
    while (getline(cin, line)) {
        if (line.empty()) continue; // 跳过空行

        // 解析第一行：将输入字符串按空格拆分为 vector<string>
        vector<string> nodes;
        stringstream ss(line);
        string nodeStr;
        while (ss >> nodeStr) {
            nodes.push_back(nodeStr);
        }

        // 读取第二行：k 的值
        string kLine;
        if (!getline(cin, kLine)) break;
        int k = stoi(kLine);

        // 动态建树
        TreeNode* root = buildTree(nodes);

        // 调用算法
        Solution sol;
        int result = sol.kthLargest(root, k);
        
        // 输出结果
        cout << result << endl;

        // 清理内存
        deleteTree(root);
    }

    return 0;
}
