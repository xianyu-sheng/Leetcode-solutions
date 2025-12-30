/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 */

// @lc code=start
class Solution {
public:
    bool judge(vector<int>& path){
        //来判断这个数组是否是满足的,幻方中每个行每个列以及斜度角的和都是15 然后每一行 每一列 加上两个斜对角一共是8对数字
        //我就直接算 最后看满足15的数字的和的个数是不是8
        int is_five=0;
        //计算列
        int sum=0;
        for(int i=0;i<9;i++){
            sum+=path[i];
            if(i==2 || i==5 || i==8){
                //检验是否等于15
                if(sum==15) is_five++;
                sum=0;
            }
        }
        //计算行
        for(int i=0;i<3;i++){
            if(path[i]+path[i+3]+path[i+6]==15) is_five++;
        }
        //计算斜对角
        //45°
        if(path[0]+path[4]+path[8]==15) is_five++;
        if(path[2]+path[4]+path[6]==15) is_five++;
        return is_five==8;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        /*
            首先，我们如果要看一下这一片数组是不是1-9的数字 如果每个数字只出现了一次 那么在进行进一步的检验是否
            是满足幻方的性质
            计算每行、每列、对角线的和是否相等----但是要怎样的去每一个位置遍历呢？一次遍历 然后在从每一个起点划出3*3的矩阵
        */
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> rel;//用来存储结果
        //然后开始遍历
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //每次以[i,j]为起点，以此划分出一个3*3的矩阵，然后检验是否满足条件
                int temp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                vector<int> path;
                for(int m=0;m<3 && i+m<row;m++){
                    for(int n=0;n<3 && j+n<col;n++){
                        if(grid[i+m][j+n]>=1 && grid[i+m][j+n]<=9){
                            path.push_back(grid[i+m][j+n]);
                            temp[grid[i+m][j+n]]-=1;
                        }
                    }
                }
                bool allZero = std::all_of(
                                std::begin(temp), 
                                std::end(temp), 
                                [](int x) { return x == 0; }
                            );
                if(path.size()==9 && allZero){
                    //调用条件判断
                    if(judge(path)){
                        rel.push_back(path);
                    }
                }
            }
        }
        return rel.size();
    }
};
// @lc code=end

