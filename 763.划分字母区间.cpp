/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
            解题思路：第一，我们要把一个字符串划分到尽可能多的片段，然后就是同一个字母最多出现在一个片段中，那么我认为
            其实这里就是需要记录一下每一个字母的开始以及结束位置
            比如就是在一个片段内，包含有两个字母，那么其结束位置自然是选择较长的那一个，同时还需要按照顺序划分
            那么先将数组的下标进行统计，记录每一个下标的位置
            不过我觉得这样效率很低，既然是贪心算法，那么我觉得这里确实好像不能通过一次的for循环就能够解决  因为贪心算法是选择局部最优
            然后进而全局最优，这里如果一个for循环来进行全局的考虑会丧失对于其他位置的观察我认为
        */
        int  last[26]={0};
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<int> rel;
        int left=0,right=0;
        for(int i=0;i<s.size();i++){
            right=max(right,last[s[i]-'a']);
            if(i==right){
                //表示已经走到当前出现的字符中的最远位置了 可以进行划分了 这里之所以没有维护一个左边界 其实就是我们这里隐含了我门如果在这个片段里包含了假设你认为应该是下一个片段的字符，那么我们的右边界就会更新 因此我们在这里就不需要再显式的维护一个左边界了
                rel.push_back(right-left+1);
                left=i+1;
            }
        }
        return rel;
    }
};
// @lc code=end

