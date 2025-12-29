/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    //上下左右的进行回溯----这里是方向的设置
    int pos[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    bool backtracking(vector<vector<char>>& board,string word,int x,int y,int index){
        // 2. 失败基础情况：越界 或者 字符不匹配 x代表行的指针  y代表列移动的指针
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
            return false;
        }
        if(index==word.size()-1)    return true;

        //标记访问
        char temp=board[x][y];
        board[x][y]='#';//标记已经访问了
        // 5. 修正：递归四个方向，只要有一个方向通了，就返回 true
        for (int i = 0; i < 4; i++) {
            int next_x = x + pos[i][0];
            int next_y = y + pos[i][1];
            // 递归匹配下一个字符 (k + 1)
            // 这里的逻辑就是：如果找到了，直接层层向上传递 true
            if (backtracking(board, word, next_x, next_y, index + 1)) {
                return true; 
            }
        }
        //回溯还原
        board[x][y]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
     /*
        这里需要使用回溯 但是因为是在一个二维数组里 那么其实这里的递归方向就是需要进行转向
     */   
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(backtracking(board,word,i,j,0))  return true;
            }
        }
        return false;
    }
};
// @lc code=end

