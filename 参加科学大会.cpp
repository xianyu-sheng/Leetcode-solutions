#include <iostream>
#include  <vector>
#include <climits>
using  namespace  std;

int main(){
    int n,m,s,e,v;
    cin >> n >> m;  //n个汽车站   m条公路
    vector<vector<int>> grid(n+1,vector<int>(n+1,INT_MAX));
    //然后输入m条边
    while(m--){
        cin >> s >> e >> v;
        grid[s][e]=v;
    }
    //开始设置起点 终点
    int  start = 1;
    int end =n;
    //设置一个mindist数组
    vector<int> mindist(n+1,INT_MAX);
    mindist[start]=0;
    //设置一个是否走过的vector《bool》数组以控制访问
    vector<bool> isVisited(n+1,false);
    //然后开始dijastral的三部曲  不需要先将start设置为已访问  为统一代码  这里提前设置过mindist[start]=0就可以了
    for(int i=1;i<=n;i++){
        int cur=-1;
        int min_val=INT_MAX;
        //1.第一步，选择距离源点最近的节点  将其加入到访问数组中
        for(int j=1;j<=n;j++){
            if(!isVisited[j] && mindist[j]<min_val){
                cur=j;
                min_val=mindist[j];
            }
        }
        if(cur==-1) break;//代表此时已经遍历完了
        //第二步，将其加入到访问数组中
        isVisited[cur]=true;
        //下一步，更新所有节点到源点的距离
        for(int j=1;j<=n;j++){
            if(!isVisited[j] && grid[cur][j]!=INT_MAX && mindist[cur]+grid[cur][j]<mindist[j]){
                mindist[j]=mindist[cur]+grid[cur][j];
            }
        }
    }
    //然后来进行输出
    if(mindist[end]==INT_MAX)   cout << -1 << endl;
    else    cout << mindist[end] << endl;
    return 0;
}