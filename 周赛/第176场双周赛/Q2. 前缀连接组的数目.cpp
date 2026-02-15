class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        //找连接组：这里因为k是一定的 那么我们又需要返回至少包含两个元素的连接组的数目 那么就可以这样 如果访问过的元素我们可以不在进行访问 因为一个单词不肯同时拥有多种k个前缀的子串 然后并且为了保持这个不重复运算 还需要加一个bool数组来维持 每次一个循环中 就去找同一个前一个子串来进行遍历
        //直接统计所有前缀组的数目 返回大于等于2的个数
        unordered_map<string,int> ans;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k)
                continue;
            string str=words[i].substr(0,k);
            ans[str]+=1;
        }
        //统计
        int rel=0;
        for(auto x:ans)
            if(x.second >= 2)
                rel++;
        return rel;
    }
};©leetcode
