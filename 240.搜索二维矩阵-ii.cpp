/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            解题思路：行中    低---->高   升序排列
                     列中    上---->下   升序排列
            总结：可能需要使用快排思想，根据哨兵位的位置快速的搜索
            但是如何高效呢----->怎样结合快排的思想，不过或许也不用这么麻烦 直接倒序查找或许也不错  直接如果是大于一列的最后一个元素 那么直接下一列  如果小于这一列的最大元素 然后直接可以从最后一个元素开始移动 一直往上 如果碰见了小于自身的元素都还没找到 那么直接列数+1  因为行内也是从左到右是增加的  正常来说这样肯定最多只会遍历一半的矩阵元素  应该能够达到要求  但是该怎样来进行呢  如果检查到右上角的元素还没有搜索到 那么就应该退出循环
        */
        if(matrix.empty() || matrix[0].empty()) return  false;
        int m=matrix.size();
        int n=matrix[0].size();

        int row=m-1;
        int col=0;
        //只要没到右上角   就可以继续
        while(row>=0  && col<n){
            //如果当前等于那么就返回true
            if(matrix[row][col] == target)    return true;
            else if(target<matrix[row][col])    row--;
            else    col++;
        }
        return  false;
    }
};
// @lc code=end

