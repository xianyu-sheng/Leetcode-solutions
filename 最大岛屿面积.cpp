#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    最大岛屿的面积，就是在标记的同时记录当前的岛屿的最大面积，并且+1 也就是在标记的时候就进行+1
    然后这里我倾向于使用广度优先搜索
*/
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int bfs(const vector<vector<int>>& table,vector<vector<bool>>& visited,int x,int y){
    int result=0;
    queue<pair<int,int>> que;
    que.push({x,y});
    result++;
    visited[x][y]=true;
    //开始进行遍历
    while(!que.empty()){
        //取出一个数据 然后对其周围四个方向的数据进行搜搜
        pair<int,int> cur=que.front();que.pop();
        //遍历四个方向
        for(int i=0;i<4;i++){
            int next_x=cur.first+dir[i][0];
            int next_y=cur.second+dir[i][1];

            if(next_x<0 || next_x >= table.size() || next_y<0 || next_y >= table[0].size())
                continue;
            if(!visited[next_x][next_y] && table[next_x][next_y]==1){
                que.push({next_x,next_y});
                visited[next_x][next_y]=true;
                result++;
            }
        }
    }
    return result;
}
int main(){
    int N,M;
    std::cin >> N >> M;
    vector<vector<int>> table(N,vector<int>(M,0));
    for( int  i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin >> table[i][j];
        }
    }
    //然后来设计一个visited数组 来标记数据是否已被访问
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    int max_rel=0;
    //进行搜索
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && table[i][j]==1){
                max_rel=max(max_rel,bfs(table,visited,i,j));
            }
        }
    }
    std::cout << max_rel << std::endl;
    return 0;
}