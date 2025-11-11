#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int V,E;    //顶点数，边数
    cin >> V >> E;
    vector<vector<int>> Tree(V+1,vector<int>(V+1,10001));   //存储顶点以及两个顶点边的权重
    for(int i=0;i<E;i++){
        int v1,v2,val;
        cin >> v1 >> v2 >> val;
        Tree[v1][v2]=val;
        Tree[v2][v1]=val;
    }
    //建立最小距离数组 以及 是否在这个最小生成树上的数组
    vector<int> minDist(V+1,10001);
    vector<bool> isInTree(V+1,false);
    //然后循环 v-1 次将所有边加入最小生成树中  使用prim三部曲
    for(int i=1;i<V;i++){
        //第一步，选择最小的边加入最小生成树
        int cur=-1;
        int min_val=INT_MAX;
        for(int j=1;j<=V;j++){
            if(!isInTree[j] && minDist[j]<min_val){
                min_val=minDist[j];
                cur=j;
            }
        }
        //第二步，将最小的哪个节点 加入到最小生成树中
        isInTree[cur]=true;
        //第三步，更新所有的没有在最小生成树上的节点到最小生成树的距离
        for(int j=1;j<=V;j++){
            if(!isInTree[j] && Tree[cur][j]<minDist[j]){
                minDist[j]=Tree[cur][j];
            }
        }
    }
    //统计结果 只需要统计从2-V的mindist的值
    int result=0;
    for(int i=2;i<=V;i++){
        result+=minDist[i];
    }

    cout <<  result << endl;
    return 0;
}

//方法2  使用kruskal方法来进行解答
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//l  r  为两个节点 val为权重
struct Edge{
    int l,r,val;
};
//节点数量
int  n=10001;
vector<int> father(n,-1);

//初始化
void  init(){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
}
//查找函数
int find(int u){
    return u==father[u]?u:(father[u]=find(father[u]));
}
//查看是否在同一个集合
bool  isSame(int u,int v){
    u=find(u);
    v=find(v);
    return u==v;
}
//加入到并差集
void  join(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v)    return;
    father[v]=u;
}

int main(){
    int v,e;
    cin >> v >> e;
    int v1,v2,val;
    vector<Edge> edges;
    while(e--){
        cin >> v1 >> v2 >> val;
        edges.push_back({v1,v2,val});
    }
    //将所有边按照从大到小的顺序排好
    sort(edges.begin(),edges.end(),[](const Edge& a,const Edge& b){
        return a.val<b.val;
    });
    //然后开始进行加入
    init();
    int result=0;
    for(auto edge : edges){
        int x=find(edge.l);
        int y=find(edge.r);
        if(x!=y){
            //代表两个节点并没有加入到最小生成树 那么现在就可以进行结果值的相加 并且将其加入到最小生成树
            result+=edge.val;
            join(x,y);
        }
    }
    cout << result << endl;
    return 0;
}