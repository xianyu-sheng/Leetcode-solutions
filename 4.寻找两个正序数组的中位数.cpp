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
//O（log(m+n))的解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            首先我们需要明白中位数的定义，即一个数组排序后的处于中间位置的数，那么如果我的数组
            的长度是一个奇数，那么直接就是中间的那个数，如果是偶数，那么就是中间位置的两个数的
            平均值，那么我们完全可以是这样，就是求出nums1  nums2的长度，然后得到是不是奇数，然后
            计算出得到中间值，我们分别需要从nums1 nums2中合起来拿出多少的元素
             
            不过这样的话，我感觉并没有达到算法O(log(m+n))的要求，我这样做其实相当于是顺序查找的
            想一想，我们是想要在两个数组中一起做二分查找，这个应该怎么办，我们实际上是求的是两个数组
            合并起来的中间的数值是吧！

            既然我们不能真的合并（因为太慢），我们尝试直接在 nums1 和 nums2 上各画一刀，把它们分成左边和右边：nums1: [ ... 左边部分 1 ... | ... 右边部分 1 ... ]nums2: [ ... 左边部分 2 ... | ... 右边部分 2 ... ]我们的目标是找到这两刀的位置，使得：数量平衡： （左边部分1 + 左边部分2）的元素个数 $\approx$ 总元素个数的一半。数值有序： 左边所有的数 $\le$ 右边所有的数。也就是说：nums1 的左边最大值 $\le$ nums2 的右边最小值nums2 的左边最大值 $\le$ nums1 的右边最小值
        */
        if(nums1.size()>nums2.size())   return findMedianSortedArrays(nums2,nums1);//保证我们来在小的数组上面进行二分
        int m=nums1.size(),n=nums2.size();
        
        int totalleft=(m+n+1)/2;

        //处理在nums1中可能出现的分割位置
        int left=0,right=m;//可能出现在最左边和最右边，这里代表的是分割线的位置，不是元素下标
        while(left <= right){
            //处理分割线，并进行交叉验证
            int i=left+(right-left)/2;
            int j=totalleft-i;

            int nums1leftMax=(i==0)?INT_MIN:nums1[i-1];//左边的最大值
            int nums1RightMin=(i==m)?INT_MAX:nums1[i];//nums1数组右边的最小值
            int nums2leftMax=(j==0)?INT_MIN:nums2[j-1];//nums2数组的左边的最大值
            int nums2RightMin=(j==n)?INT_MAX:nums2[j];//nums2数组的右半边最小值

            //然后检查是否满足完美分割
            //即nums1的左边最大值<nums2的右边最小值，nums2的左边最大值小于nums1的右边最小值，并且i+j的长度为总长度的一半
            if(nums1leftMax <= nums2RightMin && nums2leftMax <= nums1RightMin){
                //如果总长度是奇数，那么就是两个数组中左边最大值中的那个较大值
                if((m+n)%2==1)  return max(nums1leftMax,nums2leftMax);
                else    return (max(nums1leftMax,nums2leftMax)+min(nums1RightMin,nums2RightMin))/2.0;//否则就是最靠中间的两个数的平均
            }else if(nums1leftMax > nums2RightMin){
                // 说明 nums1 左边分多了 (里面的大数太大了)，分割线 i 需要往左移
                right=i-1;
            }else{
                // 说明 nums1 左边分少了 (导致 nums2 左边被迫分太多，拿到了大数)，分割线 i 需要往右移
                left=i+1;
            }
        }
        return 0.0;
    }
};
// @lc code=end

