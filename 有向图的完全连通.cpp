#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
using namespace std;
int main(){
    //solution：使用邻接链表   使用vector<list>
    //然后应该怎么做？使用广度优先遍历，将能够走到的点全部记录下来，最后来遍历如果可以到达除自己之外的其他所有点则输出1  否则输出-1
    int N,K;
    cin >> N >> K;
    vector<list<int>> photo(N+1);
    for(int i=0;i<K;i++){
        int s,t;
        cin >> s >> t;
        photo[s].push_back(t);
    }
    //这里需要使用一个map容器来存储我们遍历到的节点
    unordered_set<int> visitSet;
    queue<int> que;
    que.push(1);
    visitSet.insert(1);
    while(!que.empty()){
        int temp=que.front();que.pop();
        //然后怎样来遍历呢？如果所有节点都添加尽力啊了  那么就可以输出然后结束
        if(visitSet.size()==N){
            cout << 1 << endl;
            return 0;
        }
        //如果没有满那么就继续搜索
        for(int u:photo[temp]){
            if(visitSet.find(u)==visitSet.end()){
                visitSet.insert(u);
                que.push(u);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}