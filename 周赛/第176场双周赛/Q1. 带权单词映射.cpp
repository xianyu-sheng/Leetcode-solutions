//我的做法
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        //1.先将所有的单词的权重之和先算出来 2.然后在按照规则映射
        string ans="";
        string index="zyxwvutsrqponmlkjihgfedcba";
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                int index=words[i][j]-'a';
                sum+=weights[index];
            }
            //然后来映射
            int mod=sum%26;
            ans+=index[mod];
        }
        return ans;
    }
};©leetcode
