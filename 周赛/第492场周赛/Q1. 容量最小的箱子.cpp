class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        //使用一个变量来维护目前已知的最小容量  以及其下标  如果小于最小容量才更新下标  否则大于等于就不更新
        int min_size=INT_MAX,min_index=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && capacity[i]<min_size){
                min_size=capacity[i];
                min_index=i;
            }
        }
        return min_index;
    }
};©leetcode
