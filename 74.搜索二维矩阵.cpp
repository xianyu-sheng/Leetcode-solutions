/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            解题思路：
            条件1：每行中的整数从左到右按非严格递增顺序排列--->这代表同一行整数，从左到右，绝对是不会减少的，最次也是相等
            条件2：每行的第一个整数大于前一行的最后一个整数--->这说明，每一行之间严格单调递增的 不会出现数字交叉的情况

            那么我们怎样来进行这个数组的查找呢？
            首先，第一点，我们应该找到这个target应该是属于哪一行，我们在行内去使用二分查找
            然后，怎样判断呢？这里我们是需要使用二分查找来解决这个问题的，那么按照一般的二分查找的解题思路，我的左指针应该是指向第一行的第一个元素
            然后我的右指针应该是指向最后一行的最后一个元素，我们分别指向这两个地方 当做虚拟的一维数组进行处理
        */

        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();

        int left=0;//左指针
        int right=m*n-1;

        while(left <= right){
            //左闭右闭区间  使用<=
            int mid=left+(right-left)/2;
            //转换回二维坐标 进行判断
            int row=mid/n;
            int col=mid%n;
            int midval=matrix[row][col];
            if(midval==target)  return true;
            else if(midval < target)    left=mid+1;
            else    right=mid-1;
        }
        return false;
    }
};
// @lc code=end

