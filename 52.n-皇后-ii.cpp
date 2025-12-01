/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int count=0;
    void baxktracking(int n,int row,vector<string>& chessboard){
        //终点
        if(row==n){
            count++;
            return;
        }
        for(int col=0;col<n;col++){
            //先验证是否合法
            if(isValid(row,col,chessboard,n)){
                //放置皇后
                chessboard[row][col]='Q';
                //然后继续递归
                baxktracking(n,row+1,chessboard);
                //回溯
                chessboard[row][col]='.';
            }
        }
    }
    bool isValid(int row,int col,vector<string>& chessboard,int n){
        //检查同列是否有相同的
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q') return false;
        }
        //检查45°角
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(chessboard[i][j]=='Q')   return false;
        }
        //检查135°角
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(chessboard[i][j]=='Q')   return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        std::vector<string> chessboard(n,std::string(n,'.'));
        baxktracking(n,0,chessboard);
        return count;
    }
};
// @lc code=end

