class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
            这里怎样将其转换成我们内部的没有被选择的数据是连续的 然后题目要求是求最大点数 那么我们内部的这个就应该选择最小的
            这个size-k这么大的数组的最小点数
        */
        int sum=0;
        for(int x:cardPoints)   sum+=x;
        if(k==cardPoints.size())  return sum;
        //然后再来求出size-k的点数和最小的数组
        int sub_sum=0;
        int ans=INT_MAX;
        int len=cardPoints.size()-k;
        for(int i=0;i<cardPoints.size();i++){
            sub_sum+=cardPoints[i];
            //1.检查是否满足长度条件
            if(i-len+1<0)   continue;
            //2.如果满足再来更新
            ans=min(ans,sub_sum);
            //3.将最左端的元素弹出
            sub_sum-=cardPoints[i-len+1];
        }
        return sum-ans;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        int s = reduce(cardPoints.begin(), cardPoints.begin() + m);
        int min_s = s;
        for (int i = m; i < n; i++) {
            s += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, s);
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - min_s;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/solutions/2551432/liang-chong-fang-fa-ni-xiang-si-wei-zhen-e3gb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//正向思维
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s = reduce(cardPoints.begin(), cardPoints.begin() + k);
        int ans = s;
        for (int i = 1; i <= k; i++) {
            s += cardPoints[cardPoints.size() - i] - cardPoints[k - i];
            ans = max(ans, s);
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/solutions/2551432/liang-chong-fang-fa-ni-xiang-si-wei-zhen-e3gb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
