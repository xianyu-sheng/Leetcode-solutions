/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            解题思路：先找到0所在的行列  然后在分别置零
            这里需要注意的是避免边找边修改 这样会导致后面便利到的数据的状态发生变化
        */
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool>  zero_rows(n,false);
        vector<bool> zero_cols(m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zero_rows[i]=true;
                    zero_cols[j]=true;
                }
            }
        }
        //根据标记置零
        for(int i=0;i<n;i++){
            if(zero_rows[i]==true){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(zero_cols[j]==true){
                for(int i=0;i<n;i++)
                    matrix[i][j]=0;
            }
        }
    }
};
// @lc code=end

