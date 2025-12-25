class Solution {
public:
    unordered_map<char,string> mymap={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> rel;
    string path;
    void backtrcaking(string digits,int index){
        if(path.size()==digits.size()){
            rel.push_back(path);
            return ;
        }
        //然后取数字 以及对应的字母串
        char c=digits[index];
        string letters=mymap[c];

        for(int i=0;i<letters.size();i++){
            path.push_back(letters[i]);
            backtrcaking(digits,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        /*
            这里首先应该将数字与字母串的组合映射先建立起来，然后就是这里
            我们没次需要从一个数字代表的一组字母中选出一个来进行排列，这个
            组合起来的字符串的最大长度等于digits.size()

            然后这里求的是组合，而不是全排列 那么就需要使用一个index控制 但是重要的是我应该怎样将
            数字与字母组合对应起来呢？直接使用index即控制组合的长度，也控制深度，同时控制我们该遍历哪个
            数字的对应组合，而对于数字对应的组合，我之前想的是需不需要使用比如之前的子集的startindex来控制呢？
            我发现根本不必，因为实际上我们的index就已经控制了不是全排列的这种情况，因为这是在不同个体之间的，
            而个体之内的我觉得我们就不需要这样纠结的 因为我们就是每次取一个
        */
        backtrcaking(digits,0);
        return rel;
    }
};