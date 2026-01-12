class Solution {
public:
    int Compute(int x1,int y1,int x2,int y2){
        //我们先考虑斜边，也就是斜边最多能走多少，如果斜边走完还没到终点，那么就补差值
        int diff_x=abs(x2-x1);
        int diff_y=abs(y2-y1);
        return min(diff_x,diff_y)+abs(diff_x-diff_y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        /*
            需要经过points数组里的点，那么我就直接计算没两个点之间的距离就行
            但是不能直接使用距离公式算，这个题我们依然可以是进行简单的贪心策略
            先优先走斜边 如果斜边走到了 在考虑走左右
        */
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int x1=points[i][0],y1=points[i][1];
            int x2=points[i+1][0],y2=points[i+1][1];
            ans+=Compute(x1,y1,x2,y2);
        }
        return ans;
    }
};