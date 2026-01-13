/*
 * @lc app=leetcode.cn id=3453 lang=cpp
 *
 * [3453] 分割正方形 I
 */

// @lc code=start
class Solution {
public:
    double check(const vector<vector<int>>& squares,double midY){
        double below_area=0;//来计算以midY为分界线，下面的面积
        for(auto& s:squares){
            double y=s[1],l=s[2];
            if(y>=midY) continue;
            if(midY>=y+l)   below_area+=l*l;
            else    below_area+=l*(midY-y);
        }
        return below_area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        /*
            首先计算当前的所有正方形的面积之和，然后我们需要选择一个y坐标
            可以满足上下的面积相等，这种就是典型的背包问题，我们选择y轴尽量
            小的squares[i]来填满二分之一的总和  最后返回最小的y

            但是这样的解法不够高效，也不是最佳策略，这里其实更适合
            使用二分查找来进行解决
        */
        double total_area=0;
        double minY=1e9,maxY=-1e9;
        for(int i=0;i<squares.size();i++){
            double x=squares[i][0],y=squares[i][1],l=squares[i][2];
            total_area+=l*l;
            minY=min(minY,y);
            maxY=max(maxY,y+l);
        }
        double lowY=minY,higY=maxY;
        for(int i=0;i<100;i++){
            double midY=lowY+(higY-lowY)/2;
            //然后来检查
            if(check(squares,midY) < total_area/2.0){
                lowY=midY;
            }else{
                higY=midY;
            }
        }
        return lowY;
    }
};
// @lc code=end

