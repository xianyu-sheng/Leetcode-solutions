/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //这里需要先通过prerequisites数组构建一个入度数组 来判断开始节点
        vector<int> INdgree(numCourses,0);
        //然后统计入度
        for(int i=0;i<prerequisites.size();i++){
            INdgree[prerequisites[i][0]]+=1;
        }
        //然后来看这里是否是有入度为0的节点
        queue<int> que;
        vector<int> resul;
        //然后将入度为0的节点加入到que中
        for(int i=0;i<numCourses;i++){
            if(INdgree[i]==0){
                que.push(i);
            }
        }
        //然后开始BFS搜索
        while(!que.empty()){
            //拿出当前的节点
            int cur=que.front();que.pop();
            resul.push_back(cur);
            //然后将这个节点拿到后 将这个节点指向的节点的入度-1  然后在
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1]==cur){
                    //那么这个节点的入度就-1 然后如果为0 就加入到que
                    INdgree[prerequisites[i][0]]--;
                    if(INdgree[prerequisites[i][0]]==0){
                        //加入到que
                        que.push(prerequisites[i][0]);
                    }
                }
            }
        }
        return numCourses==resul.size();
    }
};
// @lc code=end

