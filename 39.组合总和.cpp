class Solution {
public:
    vector<vector<int>> rel;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int index){
        //结束条件---如果path中所有数的sum==target了 那么就加入结果 然后并且返回
        //遍历条件  这里可以重复选那么每次就可以从这个可以重复选的位置开始遍历
        //但是这里我们应该怎样来控制这个递归呢？那么就是通过一个剪枝 看看加进去如果大于目标就不进入了
        if(sum==target){
            rel.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(sum+candidates[i]>target)    continue;
            //否则就加入进去啊
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return rel;
    }
};