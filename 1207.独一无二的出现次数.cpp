/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        /*
            解题思路：使用一个unordered_map数组  来进行解题，以出现次数为key，然后出现了几次为的数为值，如果只有一个数那么就代表这个次数是符合
            条件的，如果出现了两个数那么就不符合条件
            反正主线就是先统计次数，然后在进行比较是否是独一无二的出现次数
            先使用map进行统计，然后在来使用vector数组来进行统计次数
        */
        unordered_map<int,int> mymap;
        for(int i=0;i<arr.size();i++){
            mymap[arr[i]]+=1;
        }
        //然后是使用一个vector数组 看看是不是每个出现次数 都为1
        vector<int> num(1001,0);
        for(auto pair : mymap){
            num[pair.second]+=1;
            //加完立马检查是否有等于2的情况
            if(num[pair.second]>=2) return false;
        }
        return true;
    }
};
// @lc code=end

