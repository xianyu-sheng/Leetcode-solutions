class Solution {
public:
    vector<vector<int>> rel;
    vector<int> path;
    void BackTracking(vector<int>& nums,vector<bool>& used){
        //递归出口
        if(path.size()==nums.size()){
            //入队列
            rel.push_back(path);
            return;
        }
        //遍历
        for(int i=0;i<nums.size();i++){
            if(used[i])
                continue;
            used[i]=true;
            path.push_back(nums[i]);
            BackTracking(nums,used);
            //回溯
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            回溯算法，就是将回溯逻辑在递归中体现，回溯与递归是一块的，当然这个题也可以使用的动态规划来
            进行解答，但是这里需要大过年太维护一个是否过这个元素的数组
        */
        vector<bool> used(nums.size(),false);
        BackTracking(nums,used);

        return rel;
    }
};