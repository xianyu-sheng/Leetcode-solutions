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