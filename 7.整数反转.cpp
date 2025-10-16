/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
//方法1:直观方法，先将整数转换为字符串，然后翻转字符串，最后再转换为整数
//注意：这里需要考虑整数的正负号以及溢出问题
class Solution {
public:
    void Flip(string& s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    int reverse(int x) {
        string str = to_string(x);

        if (x < 0) {
            Flip(str, 1, str.size() - 1);  // 只翻转数字部分
        } else {
            Flip(str, 0, str.size() - 1);  // 翻转全部
        }

        // 检查是否超出 32 位整数范围
        const int MAX_INT = 2147483647;
        const int MIN_INT = -2147483648;

        // 注意：这里我们不能直接用 stoi，因为可能溢出
        // 所以手动判断字符串长度和数值大小

        // 先转成 long long 避免中间溢出（题目允许）
        long long result = stoll(str);

        if (result > MAX_INT || result < MIN_INT) {
            return 0;
        }

        return static_cast<int>(result);
    }
};
//方法2:数学方法，直接通过对10取余和除10来实现翻转
class Solution {
public:
    int reverse(int x) {
        long long  res=0;
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        return res>INT_MAX || res<INT_MIN ?0:res;
    }
};
// @lc code=end

