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
#include <iostream>
#include <list>
#include <queue>
#include  <vector>
#include <climits>
using  namespace  std;

class  mycompre{
    public:
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second;
        }
};
struct Edge{
    int to; //邻接顶点
    int val;    //边的权重

    Edge(int t,int v):to(t),val(v){}//构造函数
};
int main(){
    int  n,m,p1,p2,val;
    cin >> n >> m;  //n个汽车站   m条公路
    vector<list<Edge>>   grid(n+1);
    //领接表的构造
    for(int i=0;i<m;i++){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2,val));
    }
    //最小距离 以及 小根堆  以及 访问数组
    int  start=1;
    int end =n;
    vector<int>  mindist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    //小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompre> pq;
    pq.push(pair<int,int>(start,0));
    mindist[start]=0;
    while(!pq.empty()){
        //1.取出距离源点最近的节点
        pair<int,int> cur=pq.top();pq.pop();
        if(visited[cur.first])  continue;
        //2.标记访问
        visited[cur.first]=true;
        //3.更新距离当前节点的距离
        for(Edge edge : grid[cur.first]){
            if(!visited[edge.to] && mindist[cur.first]+edge.val<mindist[edge.to]){
                mindist[edge.to]=mindist[cur.first]+edge.val;
                pq.push(pair<int,int>(edge.to,mindist[edge.to]));
            }
        }
    }
    if(mindist[end]==INT_MAX)   cout << -1 << endl;
    else cout << mindist[end] << endl;
    return 0;
}