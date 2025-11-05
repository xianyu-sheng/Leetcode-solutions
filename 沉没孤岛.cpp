#include <iostream>
#include <vector>
using namespace std;

/*
    题目思路：应该怎么做呢？--->上一题我们是在计算孤岛的总面积 现在我们是需要将孤岛完全的置为0 可以怎样做 从四个边开始遍历 将所有的飞孤岛的岛屿全部不标记为已经走过 然后在遍历一下visited数组 将false的地方 全部置为0
*/
//使用深度优先遍历
int dir[4][2]={1,0,0,1,-1,0,0,-1};
void  dfs(const vector<vector<int>>& table,vector<vector<bool>>& visited,int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0 || xx>=table.size() || yy<0 || yy>=table[0].size()){
            continue;
        }
        if(!visited[xx][yy] && table[xx][yy]==1){
            visited[xx][yy]=true;
            dfs(table,visited,xx,yy);
        }
    }
}
int main(){
    int  N,M;
    cin >> N >> M;
    vector<vector<int>> table(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> table[i][j];
        }
    }
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    //然后从四个边开始遍历这个table
    for(int i=0;i<N;i++){
        if(table[i][0]==1 && !visited[i][0]){
            visited[i][0]=true;
            dfs(table,visited,i,0);
        }    
        if(table[i][M-1]==1 && !visited[i][M-1]){
            visited[i][M-1]=true;
            dfs(table,visited,i,M-1);
        }   
    }
    for(int i=0;i<M;i++){
        if(table[0][i]==1 && !visited[0][i]){
            visited[0][i]=true;
            dfs(table,visited,0,i);
        }    
        if(table[N-1][i]==1 && !visited[N-1][i]) {
            visited[N-1][i]=true;
            dfs(table,visited,N-1,i);
        }   
    }
    //然后开始遍历visited数组 将对应的table位置为0
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j]){
                table[i][j]=0;
            }
        }
    }
    //输出
    for(int i=0;i<N;i++){
        for(int j=0;j<M-1;j++){
            cout << table[i][j] << ' ';
        }
        cout << table[i][M-1] << endl;
    }
    return 0;
}