/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /*
            这个就类似于层序遍历 首先，将n个房间的状态初始化为false  然后0号房间初始化为true
            进入零号房间，使用队列来维持这个顺序 一点点开  如果已经进入的房间就可以直接跳过
        */
        vector<bool> is_open(rooms.size(),false);
        is_open[0]=true;
        queue<int> que;
        for(auto num:rooms[0])  que.push(num);
        //然后开始遍历
        while(!que.empty()){
            //拿出房间号 然后标记为ture
            int index=que.front();que.pop();
            is_open[index]=true;
            //然后进入这个房间去找到应该有的数据
            for(auto num:rooms[index]){
                if(!is_open[num])   que.push(num);
            }
        }
        //最后验证
        for(int i=0;i<is_open.size();i++){
            if(!is_open[i]) return false;
        }
        return  true;
    }
};
// @lc code=end

