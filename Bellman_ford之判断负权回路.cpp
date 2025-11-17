#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n,m,p1,p2,val;
    cin >> n >> m;
    vector<vector<int>> grid;
    while(m--){
        cin >> p1 >> p2 >> val;
        grid.push_back({p1,p2,val});
    }
    //然后开始进行松弛
    int start=1;
    int end=n;
    //mindist数组
    vector<int> mindist(n+1,INT_MAX);
    mindist[start]=0;
    bool  flag=false;   //如果没有负权回路 那么松弛n-1次mindist数组就不会再变化  那么如果松弛到第n次发生变化了 那么肯定就是有负权回路
    for(int i=1;i<=n;i++){
        for(vector<int> &side : grid){
            int from=side[0];
            int to=side[1];
            int prices=side[2];
            if(i<n){
                if(mindist[from]!=INT_MAX && mindist[to]>mindist[from]+prices)  mindist[to]=mindist[from]+prices; 
            }
            else{
                if(mindist[from]!=INT_MAX && mindist[to]>mindist[from]+prices)  flag=true;
            }
        }
    }
    if(flag) cout << "circle" << endl;
    else if(mindist[end]==INT_MAX)  cout << "unconnected" << endl;
    else    cout << mindist[end] << endl;
}