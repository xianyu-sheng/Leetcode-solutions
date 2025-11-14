#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <list>

//边的数据结构
struct Edge{
    int to;
    int val;

    Edge(int t,int v):to(t),val(v){}
};
using namespace std;

int main(){
    int n,m,p1,p2,val;
    cin >> n >> m;
    vector<list<Edge>> grid(n+1);
    while(m--){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2,val));
    }
    
    vector<bool> isVisited(n+1,false);
    int start=1;
    int end=n;
    queue<int> que;
    vector<int> min_dist(n+1,INT_MAX);

    min_dist[start]=0;
    que.push(start);
    while(!que.empty()){
        //弹出队列头部元素
        int node = que.front();que.pop();
        //弹出之后 立马将其标记没有访问过 因为这里可能需要多次收缩
        isVisited[node]=false;
        //然后遍历这个节点所链接的所有边
        for(Edge& item : grid[node]){
            int from=node;
            int to=item.to;
            int prices=item.val;
            
            if(min_dist[to]  > min_dist[from]+prices){
                min_dist[to]=min_dist[from]+prices;
                //然后看其是否在队列中了 如果没有就加入
                if(isVisited[to]==false){
                    que.push(to);
                    isVisited[to]=true;
                }
            }
        }
    }
    if(min_dist[end]==INT_MAX)  cout <<  "unconnected" << endl;
    else    cout <<  min_dist[end] << endl;
}