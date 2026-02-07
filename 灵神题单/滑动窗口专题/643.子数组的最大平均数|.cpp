class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //这个题与之前的一样 我们可以怎样使用一个累计和来计算当前的窗口内的和的个数 
        //然后离开一个元素就减一部分 加入新的元素就加一部分
        int sum=0;
        double ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            //加入右端点
            sum+=nums[i];
            //然后检查当前的串口内的个数是否达到了k
            if(i-k+1<0){
                continue;
            }
            //否则代表就是够了  那么就更新
            ans=max(ans,(double)sum/k);
            sum-=nums[i-k+1];
        }
        return ans;
    }
};
