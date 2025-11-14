#include <iostream>
#include <vector>
#include <climits>
#include <list>

using namespace std;

int main(){
    int n,m,p1,p2,val;
    cin >> n >> m;
    vector<vector<int>> gird;
    for(int i=0;i<m;i++){
        cin >> p1 >> p2 >> val;
        gird.push_back({p1,p2,val});
    }
    //然后就可以设置mindist数组  以及开始遍历
    int start=1;
    int end=n;
    vector<int> min_dist(n+1,INT_MAX);
    min_dist[start]=0;

    //开始n-1次松弛
    for(int i=1;i<n;i++){
        for(vector<int>& side : gird){
            int from=side[0];
            int to=side[1];
            int prices=side[2];

            if(min_dist[from]!=INT_MAX  && min_dist[to] > min_dist[from]+prices){
                min_dist[to]=min_dist[from]+prices;
            }
        }
    }
    if(min_dist[end]==INT_MAX)  cout <<  "unconnected" << endl;
    else    cout <<  min_dist[end] << endl;
}