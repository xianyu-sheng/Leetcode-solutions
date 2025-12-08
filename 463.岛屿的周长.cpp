class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        /*
            首先统计有多少个岛屿 然后找到一个岛屿  如果其四周全是水域那么周长就不变，如果四周有一个岛屿接壤，那么就减少两条边
        */
        int cycles=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    cycles+=4;
                    //然后就开始看四周
                    //检查上面
                    if(i-1>=0 && grid[i-1][j]==1)   cycles-=1;
                    //检查下面
                    if(i+1 < row && grid[i+1][j]==1)    cycles-=1;
                    if(j-1>=0 && grid[i][j-1])  cycles-=1;
                    if(j+1 < col && grid[i][j+1])   cycles-=1;
                }   
            }
        }
        return cycles;
    }
};