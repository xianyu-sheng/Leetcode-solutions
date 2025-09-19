#include <iostream>
#include <vector>
using namespace std;

int main(){
    //背包的容量为C  物品的种类为N  每种矿石有一个重量W[i] 价值 V[i] 以及个数K[i]
    //第一行输入  容量C 以及 物品中类N
    int C,N;
    cin>>C>>N ;
    //第二行输入N钟矿石的重量
    vector<int> weight(N,0);
    for(int i=0;i<N;i++)
        cin>>weight[i];
    //第三行输入N种矿石的价值
    vector<int> value(N,0);
    for(int i=0;i<N;i++){
        cin>>value[i];
    }
    //第四行输入N种矿石的个数
    vector<int> k_nums(N,0);
    for(int i=0;i<N;i++){
        cin>>k_nums[i];
    }
    //设置一个dp数组
    vector<int> dp(C+1,0);
    for(int i=0;i<N;i++){
        //遍历物品
        for(int j=C;j>=k_nums[i];j--){
            //遍历背包容量
            for(int k=1;k<=k_nums[i] && (j-k*weight[i])>=0;k++){
                dp[j]=max(dp[j],dp[j-k*weight[i]]+k*value[i]);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}