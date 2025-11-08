#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> table(N+1,0);
int main(){
    
    cin >> N >> M;
    void join(int,int);
    int find(int);
    bool  isame(int,int);
    

    //初始化并查集
    for(int i=1;i<=N;i++){
        table[i]=i;
    }
    //然后输入M行的边
    for(int i=0;i<M;i++){
        int s,t;
        cin >> s >> t;
        join(s,t);
    }
    int  source,destination;
    cin  >> source >> destination;
    //查找是否属于同一个根节点
    bool  isexist=isame(source,destination);
    if(isexist) cout << 1 << endl;
    else    cout << 0 << endl;
    return 0;
}
int find(int s){
    return s==table[s]?s:table[s]=find(table[s]);
}
bool isame(int s,int t){
    int ss=find(s);
    int tt=find(t);
    return ss==tt;
}
void join(int s,int t){
    int ss=find(s);
    int tt=find(t);
    if(ss==tt)  return;
    table[ss]=tt;
}