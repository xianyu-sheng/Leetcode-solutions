/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
            解题思路：这是一个纯粹的数学题  同时我们还可以发现的是
            如果矩阵是奇数的 那么最中心的那个值不用变 如果是偶数的话 那么全都要转换一下
            其实我们可以想象的是 这样完全可以使用四个指针来进行遍历 因为矩阵矩阵 他是一个方形的  那么
            我们只需要把握住四个角 然后顺时针转动就行
            比如  matrix[0][0]=left_1    matrix[0][n-1]=right_1
                matrix[n-1][0]=left_2   matrix[n-1][n-1]=right_2
            然后不停的转  这里应该需要使用两层的for循环  里层控制一层的遍历  外层控制整个矩阵的遍历也就是控制他们一层层的往里面缩  直到达到某个临界点退出循环
        */
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;
            int last = n - 1 - layer;
            for (int i = first; i < last; ++i) {
                int offset = i - first;

                // 保存左上角的值
                int temp = matrix[first][i];

                // 左下 -> 左上
                matrix[first][i] = matrix[last - offset][first];

                // 右下 -> 左下
                matrix[last - offset][first] = matrix[last][last - offset];

                // 右上 -> 右下
                matrix[last][last - offset] = matrix[i][last];

                // 左上 -> 右上
                matrix[i][last] = temp;
            }
        }
    }
};
// @lc code=end

