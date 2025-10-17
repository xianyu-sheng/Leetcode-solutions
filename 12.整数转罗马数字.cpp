/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
//方法1：自己想的方法，将每一个数量级的处理抽象为一种函数，然后在考虑
//不同的数字级别，进行同样的处理逻辑拼接
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string Roman(int num, int exp) {
        // 定义每一级对应的罗马字符：低、中、高
        char low, mid, high;
        
        if (exp == 1) {
            low = 'I'; mid = 'V'; high = 'X';
        } else if (exp == 10) {
            low = 'X'; mid = 'L'; high = 'C';
        } else if (exp == 100) {
            low = 'C'; mid = 'D'; high = 'M';
        } else if (exp == 1000) {
            low = 'M'; mid = ' '; high = ' '; // 千位没有 mid 和 high
        }

        string result = "";

        switch (num) {
            case 1:
                result = low;
                break;
            case 2:
                result = string(2, low); // "II"
                break;
            case 3:
                result = string(3, low); // "III"
                break;
            case 4:
                result = string(1, low) + mid; // "IV"
                break;
            case 5:
                result = mid;
                break;
            case 6:
                result = mid + string(1, low); // "VI"
                break;
            case 7:
                result = mid + string(2, low); // "VII"
                break;
            case 8:
                result = mid + string(3, low); // "VIII"
                break;
            case 9:
                result = string(1, low) + high; // "IX"
                break;
            default: // num == 0
                result = "";
                break;
        }

        return result;
    }

    string intToRoman(int num) {
        string rel = "";
        int exp = 1;

        while (num > 0) {
            int digit = num % 10;
            rel += Roman(digit, exp);
            num /= 10;
            exp *= 10;
        }

        // 翻转字符串（因为我们是从个位开始处理的）
        reverse(rel.begin(), rel.end());
        return rel;
    }
};

//方法2：贪心算法，从大到小处理
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> values = {
            {1000, "M"}, 
            {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, 
            {1, "I"}
        };

        string result = "";
        for (auto& p : values) {
            while (num >= p.first) {
                result += p.second;
                num -= p.first;
            }
        }
        return result;
    }
};
// @lc code=end

