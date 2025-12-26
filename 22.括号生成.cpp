class Solution {
public:
    vector<string> rel;
    string path;
    void backtrcking(int n,int left,int right){
        /*
            使用两个变量来控制左括号与右括号的使用数量以及当前状态，以控制下一步应该怎样走
        */
        if(right==left && (right+left)==2*n){
            rel.push_back(path);
            return;
        }
        //尝试加括号
        if(left<n){
            //还可以加左括号
            path+='(';
            backtrcking(n,left+1,right);
            path.pop_back();
        }
        if(right<left){
            //还可以加左括号
            path+=')';
            backtrcking(n,left,right+1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrcking(n,0,0);
        return rel;
    }
};