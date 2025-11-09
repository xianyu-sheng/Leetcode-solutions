class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        //方法1：使用容器存储相同元素的下标 并遍历所有组合
        if(nums.size()<3)
            return -1;
        unordered_map<int,vector<int>> index_map;
        for(int i=0;i<nums.size();i++){
            index_map[nums[i]].push_back(i);
        }
        int rel=INT_MAX;
        //遍历每一个值
        for(auto& [val,index] : index_map){
            if(index.size() <3)
                continue;
            //枚举所有的三元组合
            for(int i=0;i<index.size();++i){
                for(int j=i+1;j<index.size();++j){
                    for(int k=j+1;k<index.size();++k){
                        int temp=abs(index[i]-index[j])+
                                abs(index[j]-index[k])+
                                abs(index[k]-index[i]);
                        rel=min(rel,temp);
                    }
                }
            }
        }
        return rel==INT_MAX ? -1:rel;
    }
};©leetcode