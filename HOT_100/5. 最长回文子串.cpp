#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 中心扩散法求解最长回文子串
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return ""; // 空串特殊处理
        int ans_left = 0, ans_right = 0;

        // 处理奇数长度回文串（中心为单个字符）
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            // 向左右扩散，直到不满足回文条件
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 更新最长回文子串的左右边界（左闭右开）
            if (r - l - 1 > ans_right - ans_left) {
                ans_left = l + 1;
                ans_right = r;
            }
        }

        // 处理偶数长度回文串（中心为两个相邻字符）
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > ans_right - ans_left) {
                ans_left = l + 1;
                ans_right = r;
            }
        }

        // 截取最长回文子串并返回
        return s.substr(ans_left, ans_right - ans_left);
    }
};

//一次扫描版  合并奇数偶数扫描
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans_left = 0, ans_right = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            int l = i / 2, r = (i + 1) / 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 循环结束后，s[l+1] 到 s[r-1] 是回文串
            if (r - l - 1 > ans_right - ans_left) {
                ans_left = l + 1;
                ans_right = r; // 左闭右开区间
            }
        }

        return s.substr(ans_left, ans_right - ans_left);
    }
};

int main() {
    // 循环读取输入字符串，支持多组测试用例
    string s;
    while (cin >> s) {
        Solution sol;
        string res = sol.longestPalindrome(s);
        cout << res << endl;
    }
    return 0;
}
