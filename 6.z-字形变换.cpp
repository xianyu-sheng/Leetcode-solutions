/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        /*
            这里说的Z字形排列 我认为其实更应该说成是N字形排列差不多 不过如何将这个问题给抽象一下呢
            这个题其实更像是一个模拟题  我们处于第一行的时候，那么此时我们应该就是只+行号  当行号达到最低端的时候 我们需要一边-行号  一边+列号  此时又到了第一行  然后继续往复 不过应该设计多少列呢  这里可能需要一个计算公式 使用数学来推导一下---->动态的vector数组分配
        */

        if(s.empty()  || numRows==1)    return s;
        vector<string>  rows(numRows);//每一行都是一个字符串，其实这里不用去刻意的管列号，因为最后他是横着读的 只需要把握好相对顺序即可
        int row=0;
        bool goingdown=false;//状态机思想，当达到第一行或者是最下面一行时 就应该调转方向来

        for(char c: s){
            rows[row]+=c;

            //控制方向变化
            if(row==0 || row==numRows-1){
                goingdown=!goingdown;
            }
            row+=goingdown?1:-1;
        }

        //拼接结果
        string  res="";
        for(const string& ss:rows)
            res+=ss;
        return res;
    }
};

// @lc code=end

