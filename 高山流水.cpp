#include <iostream>
#include <vector>
using namespace std;

int n,m;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
void dfs(vector<vector<int>>& table,vector<vector<bool>>& visit,int x,int y){
    //将外面的判断逻辑放里面来
    if(visit[x][y]) return;
    visit[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx <0 || xx>=n || yy<0 || yy>=m) continue;
        if(table[x][y] > table[xx][yy]) continue;
        dfs(table,visit,xx,yy);
    }
    return;
}
//从两个边界遍历数组  然后发现两个边界都标记出的较高点 那么就是需要输出的坐标
int main(){
    cin >> n >> m;
    vector<vector<int>> table(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> table[i][j];
        }
    }
    //第一个边界出发
    vector<vector<bool>> first_border(n,vector<bool>(m,false));
    //第二个边界出发
    vector<vector<bool>> second_border(n,vector<bool>(m,false));
    //然后开始遍历 左右出发
    for(int i=0;i<n;i++){
        dfs(table,first_border,i,0);
        dfs(table,second_border,i,m-1);
    }
    //上下出发
    for(int i=0;i<m;i++){
        dfs(table,first_border,0,i);
        dfs(table,second_border,n-1,i);
    }
    //然后开始同时遍历 两个bool数组 同时为true那么就输出
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(first_border[i][j] && second_border[i][j])   cout<<i<<' '<<j<<endl;
        }
    }
    return 0;
}