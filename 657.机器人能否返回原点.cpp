/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
     /*
        记录机器人当前的位置为0,0 然后向右就是x+1,y
        向左就是 x-1,y
        向上就是 x,y-1
        向下就是x,y+1
     */   
        vector<int> pos(2,0);
        for(int i=0;i<moves.size();i++){
            switch(moves[i]){
                case 'R':
                    pos[0]+=1;
                    break;
                case 'L':
                    pos[0]-=1;
                    break;
                case 'U':
                    pos[1]-=1;
                    break;
                case 'D':
                    pos[1]+=1;
                    break;
            }
        }
        return pos==vector<int>({0,0});
    }
};
// @lc code=end

