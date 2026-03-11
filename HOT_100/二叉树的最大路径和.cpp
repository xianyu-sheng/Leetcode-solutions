#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res;

int dfs(TreeNode* u) {
    if (!u) return 0;
    int l = max(dfs(u->left), 0);
    int r = max(dfs(u->right), 0);
    res = max(res, u->val + l + r);
    return u->val + max(l, r);
}

// 根据数组建树（-1 表示空节点）
TreeNode* build(const vector<int>& a, int& idx) {
    if (idx >= a.size() || a[idx] == -1) {
        idx++;
        return NULL;
    }
    TreeNode* u = new TreeNode(a[idx++]);
    u->left = build(a, idx);
    u->right = build(a, idx);
    return u;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int idx = 0;
    TreeNode* root = build(a, idx);
    res = -INF;
    dfs(root);
    cout << res << endl;
    return 0;
}
