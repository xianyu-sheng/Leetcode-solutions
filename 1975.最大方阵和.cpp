class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        /*
            这里我想起我们之前使两个序列相等的最小代价了  我是否可以统计负数个数 然后如果是偶数 后面就全需要翻转
            然后如果是奇数个  那么就剩最后那个最小的 ---  并且那个最小的绝对值我们可以是看看其是否是整个矩阵最小
            整个矩阵最小那么我们就让他成为负数
            但是这里我比较疑惑的是 这里需要相邻才可以一起乘----这里我想通了就是 负号是可以传递的 
            比如 -1 1 1 -1  那么我们完全是可以这样的  1 -1 1 -1    ---> 1 1 -1 -1  中间的每个位置会连续两次乘以-1  那么就恢复原位了就
        */
        long long totalsum=0;//总和
        long long negCount=0;//负数的个数
        int min_val=INT_MAX;//最小的绝对值

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                totalsum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)  negCount++;
                //更新绝对值最小的元素
                min_val=min(min_val,abs(matrix[i][j]));
            }
        }
        if(negCount%2==0)   return totalsum;
        else    return  totalsum-2*min_val;
    }
};