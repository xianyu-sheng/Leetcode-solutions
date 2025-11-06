#include <iostream>
#include <vector>
using namespace std;
/*
    题目理解：只有一个岛屿，那么我们就需要将外围的岛屿坐标记录起来，然后进行记录
    反正只有一个岛屿  但是我们需要将其进行排列 怎么排列呢   就按顺指针进行排列
    就是指的是 如果纵坐标相同 那么横坐标大的排后面
              如果横坐标相同 那么纵坐标大的小的排后面
*/
int n,m;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int main(){
    cin >> n >> m;
    vector<vector<int>> table(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> table[i][j];
        }
    }
    int relsult=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(table[i][j]==1){
                for(int k=0;k<4;k++){
                    int xx=i+dir[k][0];
                    int yy=j+dir[k][1];
                    if(xx<0 || xx>=n || yy<0 || yy>=m || table[xx][yy]==0)  relsult++;
                }
            }
        }
    }
    cout << relsult << endl;
    return 0;
}