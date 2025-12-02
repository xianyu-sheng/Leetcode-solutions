/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        /*
            使用队列来存储议员的下标 
            最后检查那个队列为空了 则获胜
        */
        queue<int> radiant,dire;
        int n=senate.size();
        //下标进队
        for(int i=0;i<n;i++){
            if(senate[i]=='R')  radiant.push(i);
            else    dire.push(i);
        }
        //然后来分别的便利
        while(!radiant.empty() && !dire.empty()){
            int r=radiant.front();radiant.pop();
            int d=dire.front();dire.pop();
            if(r<d){
                //r获胜 继续排队
                radiant.push(r+n);
            }else{
                dire.push(d+n);
            }
        }
        //最后谁不为空谁获胜
        return !radiant.empty()?"Radiant":"Dire";
    }
};
// @lc code=end

