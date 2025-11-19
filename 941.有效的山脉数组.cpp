/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        /*
            解题思路：这个题的思路也就是说是我门要选择一个山峰 然后我们的两边都比我们小
            用我上一题的方法刚刚好  只要有一个节点满足两边都比自己小  那么就返回true
            否则 返回false
        */
        if(arr.size()<3)    return false;
        int left=0;
        int right=arr.size()-1;
        while(left < arr.size()-1 && arr[left]<arr[left+1]) left++;
        while(right>0 && arr[right]<arr[right-1])   right--;
        if(left==right  && right!=arr.size()-1 && left!=0)  return true;
        return false;
    }
};
// @lc code=end

