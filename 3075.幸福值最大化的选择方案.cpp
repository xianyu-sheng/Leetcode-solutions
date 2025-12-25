/*
 * @lc app=leetcode.cn id=3075 lang=cpp
 *
 * [3075] 幸福值最大化的选择方案
 */

// @lc code=start
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        /*
            解题思路：这里我们首先完全可以将数据进行排序，然后维护一个全局的随选择次数开始幸福值相减的方案
            并且维护一个vector<bool>数组 来记录那些孩子已经被挑选走
        */
        int n=happiness.size()-1;
        sort(happiness.begin(),happiness.end());
        long long sub=0,sum=0;//维护最大的幸福值以及减的方案
        while(k--){
            sum=sum+((happiness[n]-sub)>=0?(happiness[n]-sub):0);
            n--;
            sub++;
        }
        return sum;
    }
};
// @lc code=end

