/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> rel;
    vector<string> path;
    //判断是否是回文串的字符
    bool loopstring(const string& s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            right--;left++;
        }
        return true;
    }
    //递归加回溯
    void backtracking(string s,int startindex){
        //递归出口
        if(startindex>=s.size()){
            rel.push_back(path);
            return;
        }
        //然后开始遍历其他
        for(int i=startindex;i<s.size();i++){
            //先将这部分数据截取下来u
            if(loopstring(s,startindex,i)){
                string sub=s.substr(startindex,i-startindex+1);
                //加入到path
                path.push_back(sub);
                //然后继续递归
                backtracking(s,i+1);
                //回溯
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        /*
            分割回文串：那么这里就需要一边分割 然后同时判断分割下来的字符串是否是回文串
        */
        backtracking(s,0);

        return rel;
    }
};
// @lc code=end

