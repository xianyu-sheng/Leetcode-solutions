#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序+固定一个数 使用双指针
        vector<vector<int>> rel;
        int n=nums.size();

        //1.先排序
        sort(nums.begin(),nums.end());

        //2.遍历固定的第一个数nums[i]
        for(int i=0;i<n;i++){
            //剪枝优化:如果排序后的第一个数已经大于0  那么后面的数都大于0  没必要继续
            if(nums[i]>0)   break;

            //对第一个数进行去重
            if(i>0 &&  nums[i]==nums[i-1])  continue;

            //3.双指针寻找剩下的两个数
            int left=i+1,right=n-1;
            while(left<right){
                int  sum=nums[i]+nums[left]+nums[right];

                if(sum==0){
                    rel.push_back({nums[i],nums[left],nums[right]});

                    //然后对left right  去重
                    while(left< right && nums[left]==nums[left+1])  left++;
                    while(right>left && nums[right]==nums[right-1]) right--;

                    //找到一组解  开始移动
                    left++;right--;
                }else if(sum < 0){
                    left++;//此时和太小
                }else{
                    right--;//和太大
                }
            }
        }
        return rel;
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
        Solution sol;
        vector<vector<int>> res=sol.threeSum(nums);
        for(const auto num:res) for(const auto& x:num)  cout << x << " ";
    }
    return 0;
}
