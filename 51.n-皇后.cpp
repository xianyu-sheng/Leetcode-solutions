/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> rel;
    //递归+回溯
    void backtrcaking(int n,int row,vector<string>& chessboard){
        //递归出口条件---这里我们一行行的来放置
        if(row==n){
            rel.push_back(chessboard);
            return;
        }
        //如果还没放置够 那么就继续放置
        for(int col=0;col<n;col++){
            //其实每一行都能够放  就看放在哪里比较合适
            //如果放在这里是正确的 那么再继续
            if(isValid(chessboard,row,col,n)){
                //放在这个位置合法 那么就将其修改 并继续递归
                chessboard[row][col]='Q';
                backtrcaking(n,row+1,chessboard);
                chessboard[row][col]='.';
            }
        }
    }
    bool isValid(const vector<string>& chessboard,int row,int col,int n){
        //然后来进行判断
        //同一行来进行判断
        for(int i=0;i<n;i++){
            if(chessboard[row][i]=='Q')
                return false;
        }
        //统一列来进行判断
        for(int j=0;j<n;j++){
            if(chessboard[j][col]=='Q') return false;
        }
        //然后四十五度来进行判断
        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
            if(chessboard[i][j]=='Q')   return false;
        }
        //然后145°进行判断
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(chessboard[i][j]=='Q')   return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        /*
            N皇后问题---除了判断递归回溯之外 就是需要进行判断，每个位置能否放置皇后
        */
        vector<string> chessboard(n,string(n,'.'));
        backtrcaking(n,0,chessboard);
        return rel;
    }
};
// @lc code=end

