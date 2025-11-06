#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
    题目理解：首先，这个题不是简单的就是求出原本的最大面积然后+1 而是可以与其他的岛屿链接在一起，然后
    求出共同的最大面积 那么我们应该怎么来进行维护呢？
    这里其实可以这样一个角度来思考就是 我们的岛屿是进行上下左右四个方向来进行延伸 但是这里我们或许可以考虑的是进行斜对角的延伸---但是只有一次机会 如果一次斜对角能够延伸 那么就记录下来这次的延伸起来的值
    或者思路还可以进行别的变化   为什么我不能先将所有的水域给先标记为别的数呢  然后再来进行拼接 不不 还是不行  这样0不就是特殊值吗？  
    或许就可以直接探寻是否有斜对角的点 有就可以直接在这个点上加上探寻点 但是需要进行加上一个全局的bool变量 来维护只是一次的这个条件
*/
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int n,m;
int count=0;
void dfs(vector<vector<int>>& table,vector<vector<bool>>& visited,int x,int y,int mark){
    if(visited[x][y] || table[x][y]==0) return;
    visited[x][y]=true;
    table[x][y]=mark;
    count++;
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0 || xx>=n || yy<0 || yy>=m)  continue;
        dfs(table,visited,xx,yy,mark);
    }
}
int main(){
    cin >> n >> m;
    vector<vector<int>> table(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> table[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    unordered_map<int,int> table_num;
    int mark=2;
    bool isALLGrif=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(table[i][j]==0)  isALLGrif=false;
            if(!visited[i][j] && table[i][j]==1){
                count=0;
                dfs(table,visited,i,j,mark);
                table_num[mark]=count;
                mark++;
            }
        }
    }
    //然后先看看是不是全是陆地 全是陆地的话直接结束程序
    if(isALLGrif)  {
        cout << n*m <<endl;
        return 0;
    }
    //否则 就继续下面的拼接逻辑
    int result=0;
    unordered_set<int> visitedtable;//标记访问过的岛屿
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            count=1;
            visitedtable.clear();//每次使用时清零
            if(table[i][j]==0){
                for(int k=0;k<4;k++){
                    int xx=i+dir[k][0];
                    int yy=j+dir[k][1];
                    if(xx <0 || xx>=n || yy <0 || yy>=m)    continue;
                    if(visitedtable.count(table[xx][yy]))   continue;
                    count+=table_num[table[xx][yy]];
                    visitedtable.insert(table[xx][yy]);
                }
            }
            result=max(result,count);
        }
    }
    cout << result <<endl;
    return 0;
}