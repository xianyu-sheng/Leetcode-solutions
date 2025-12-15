/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
            解题思路：这里我我们需要将题意抽象一下 找出左上方和右上角的下标的规律
            可以这样的思路吗  就是当前的数值就是当前的dp[i][j]=dp[i-1][j-1%dp[i-1].size()]+dp[i-1][j+1%dp[i-1].size()] 然后如果是第0列以及最后一列就是1
        */
        vector<vector<int>> rel(numRows);
        for(int i=0;i<numRows;i++){
            //先扩展大小
            rel[i].resize(i+1);
            //然后先定边界
            rel[i][0]=1;
            rel[i][i]=1;
            //然后开始循环
            for(int j=1;j<i;j++){
                rel[i][j]=rel[i-1][j-1]+rel[i-1][j];
            }
        }
        return rel;
    }
};
// @lc code=end

