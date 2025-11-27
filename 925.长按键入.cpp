/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        /*
            首先，首先统计字符出现的次数  然后在来比对在相同位置 typed的出现次数是不是大于等于name
            这种方法不得行 我认为还是应该不得行   这里我们其实可以明确的知道的是 这里typed的长度大于等于name
            那只有这样  我们在便利name的时候 就需要进行的是  找到name的这个相同字符区间的长度 然后去typed中找
            其该字符区间的长度必须大于等于name的区间长度
        */
        int i = 0, j = 0;
        int m = name.size(), n = typed.size();
        while (i < m && j < n) {
            char ch = name[i];
            int cntName = 0;
            while (i < m && name[i] == ch) { ++i; ++cntName; }

            int cntTyped = 0;
            while (j < n && typed[j] == ch) { ++j; ++cntTyped; }

            if (cntTyped < cntName) return false;   // 长按必须 ≥ 原始
        }
        // 必须同时走到末尾
        return i == m && j == n;
    }
};
// @lc code=end

