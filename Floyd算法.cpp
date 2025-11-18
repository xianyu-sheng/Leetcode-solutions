#include <iostream>
#include <vector>

using namespace  std;
int main(){
    int n,m,u,v,w,q,start,end;
    cin >> n >> m;
    vector<vector<vector<int>>> grid(n+1,vector<vector<int>>(n+1,vector<int>(n+1,10005)));
    for(int i=0;i<m;i++){
        cin  >> u >> v >> w;
        grid[u][v][0]=w;
        grid[v][u][0]=w;
    }
    //开始floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                grid[i][j][k]=min(grid[i][j][k-1],grid[i][k][k-1]+grid[k][j][k-1]);
            }
        }
    }
    //输出结果
    cin  >> q;
    while(q--){
        cin  >>  start >> end;
        if(grid[start][end][n]==10005)  cout << -1 << endl;
        else    cout << grid[start][end][n] << endl;
    }
    return 0;
}