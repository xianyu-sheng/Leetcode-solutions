class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        /*
            暴力解法
            空间换时间  使用一个vector数组来存储这个结果 然后遍历
        */
        if(nums.size()<3)
            return -1;
        unordered_map<int,vector<int>> table;
        for(int i=0;i<nums.size();i++){
            table[nums[i]].push_back(i);
        }
        int rel=INT_MAX;
        //遍历table数组
        for(int i=1;i<=table.size();i++){
            if(table[i].size()<3)
                continue;
            for(int s=0;s<table[i].size()-2;++s){
                int ii=table[i][s];
                int jj=table[i][s+1];
                int kk=table[i][s+2];
                int temp=abs(ii - jj) + abs(jj - kk) + abs(kk - ii);
                rel=min(rel,temp);
            }
        }
        return rel==INT_MAX?-1:rel;
    }
};©leetcode