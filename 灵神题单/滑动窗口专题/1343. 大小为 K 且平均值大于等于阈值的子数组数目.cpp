class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //长度为k 需要算平均值 如果大于平均值 就可以加ans
        int ans=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            //右端点进
            sum+=arr[i];
            //先检查是否达到了子数组长度为k
            if(i-k+1<0) continue;
            //否则我们就可以去计算这里的平均值 以及平均值是否达到阈值
            double average_value=sum/k;
            if(average_value>=threshold)    ans++;
            sum-=arr[i-k+1];
        }
        return ans;
    }
};
