/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
int romanToInt(string s) {
    unordered_map<string, int> map = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };
    
    int result = 0, i = 0;
    while (i < s.size()) {
        string two = s.substr(i, 2);
        string one = s.substr(i, 1);
        if (map.find(two) != map.end()) {
            result += map[two];
            i += 2;
        } else {
            result += map[one];
            i++;
        }
    }
    return result;
}
};
// @lc code=end

