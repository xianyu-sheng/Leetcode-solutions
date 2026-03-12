#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution1 {
public:
    //深度搜索
    int dfs(const vector<int>& nums,int target,int index,int current_sum,unordered_map<string,int>& memo){
        //终止条件
        if(index == nums.size()){
            return current_sum==target ? 1:0;
        }

        //构造备忘录的key
        string key=to_string(index)+","+to_string(current_sum);
        if(memo.count(key)){return memo[key];}//直接使用之前的状态结果}
        //分支1：+号
        int add=dfs(nums,target,index+1,current_sum+nums[index],memo);
        int sub=dfs(nums,target,index+1,current_sum-nums[index],memo);

        //记录状态：并返回
        memo[key]=add+sub;
        return memo[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //方法1：使用递归+回溯来解决
        //采用记忆化搜索 防止大量重复计算
        unordered_map<string,int> memo;
        return dfs(nums, target, 0, 0, memo);
    }
};
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //方法2：转换为动态规划问题--01背包问题
        /*
            假设我们将数组中的元素分为两个集合：
            * P为所有被分配+的元素之和
            * N为所有被分配-的元素的绝对值之和

            那么根据题目意思：我们可以知道
            1.P-N=target(target也为定值)
            2.P+N=sum(数组中所有元素的总和,sum为定值)

            将这两个等式相加可以得到：
                2P=target+sum
                P=(target+sum)/2
            因此这里就把问题转换成了一个经典的0-1背包问题，在数组中找一些元素，使他们的和刚好为P
        */
        int sum=0;
        for(int x:nums) sum+=x;
        if(abs(target)>sum || (target+sum)%2==1)    return 0;
        int bigSize=(target+sum)/2;
        //dp[j]表示 填满容量为j的背包 有dp[j]种方法
        vector<int> dp(bigSize+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=bigSize;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[bigSize];
    }
};

int main(){
    //输入参数
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int target;cin>>target;
        Solution2 sol;
        int res=sol.findTargetSumWays(nums,target);
        cout << res << endl;
    }
    return 0;
}
