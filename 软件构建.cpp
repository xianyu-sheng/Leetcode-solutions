#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

//这个软件构建的本质其实就是构建一个有向图
int main(){
    int N,M;    //N个文件   M条依赖关系
    cin >> N >> M;
    unordered_map<int,vector<int>> umap;    //记录文件之间的依赖关系
    vector<int> inDegree(N,0);  //记录每个文件节点的入度
    vector<int> result; //记录最后的结果顺序
    queue<int> que; //用来加入入度为0的节点  进行处理

    //首先，先输入m行 将数据载入
    int s,t;
    while(M--){
        cin >> s >> t;
        umap[s].push_back(t);
        inDegree[t]++;
    }
    //然后开始处理
    for(int i=0;i<N;i++){
        if(inDegree[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int cur=que.front();que.pop();
        result.push_back(cur);
        //然后开始将所有需要依赖的他的节点的入度-1
        vector<int> temp=umap[cur];
        if(temp.size()){
            for(int i=0;i<temp.size();i++){
                inDegree[temp[i]]--;
                if(inDegree[temp[i]]==0)   que.push(temp[i]);
            }
        }
    }
    //然后看看是否有环  没有环就输出顺序 否则就输出-1
    if(result.size()==N){
        for(int i=0;i<N-1;i++){
            cout << result[i] << ' ';
        }
        cout << result[N-1];
        return 0;
    }else{
        cout << -1;
    }
    return 0;
}