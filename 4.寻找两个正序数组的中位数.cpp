/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //这个题目的意思我看是需要先将这两个数组进行合并 然后取其中间的那位 或者中间的两位
        //但是肯定需要排序的
        vector<int>  rel;
        //怎样从nums数组里取数据
        int nums1_size=nums1.size();
        int nums2_size=nums2.size();
        int i=0,j=0;
        while(i<nums1_size && j<nums2_size){
            //每次只往rel数组里添加一个元素  对其进行比较
            if(nums1[i]<=nums2[j]){
                //那么就加入nums1[i]  并且i++  j保持不变
                rel.push_back(nums1[i]);
                i++;
            }
            else{
                rel.push_back(nums2[j]);
                j++;
            }
        }
        // 把剩下的元素全部加入
        while (i < nums1_size) {
            rel.push_back(nums1[i]);
            i++;
        }
        while (j < nums2_size) {
            rel.push_back(nums2[j]);
            j++;
        }
        int  size=rel.size();
        if(size%2==0){
            return (rel[size / 2 - 1] + rel[size / 2]) / 2.0;
        }
        else{
            return rel[size / 2];
        }
    }
};
// @lc code=end

