/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
            这里可以看见的是，他这里旋转一次就等于将最后一个位置的元素，放到数组的开头
            这样如果的结果其实可以很显然的得知，就是我们的数组始终是有序的，是有迹可循的
            如果我们的开始元素，大于我们的最后的结束元素，这说明我们的旋转次数%n>0 如果等于0要不是已经转过一圈要不就是还没转不需要管
            然后就会始终有序，并且我们说是需要寻找最小值  那么就存在找边界问题，又需要O(log n)的时间复杂度，使用二分查找 不能直接排序
            排序是O（n）
            1.如果是nums[0]<nums[n-1],直接return  nums[0]
            2.如果nums[0]>nums[n-1]
                进行二分查找，nums[mid]>nums[right]【这里说明一下，为什么要与右端比，而不是左端比，是因为如果目前我们的旋转是有效的话，那么我们的右端值是一定小于旋转过来的整体，并且同时大于当前右端的最左端的】  此时说明mid还在左端高端的数据中，放心大胆地left+1
                如果nums[mid]<nums[right]---->这里就不能直接的就right-1  必须先探测一下 如果nums[mid]>nums[mid-1]那么在-1否则
                直接return
        */
        int n=nums.size();
        if(n==1)    return nums[0];
        if(nums[0]<nums[n-1])   return nums[0];
        int left=0,right=n-1;
        int mid=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }else{
                if(nums[mid]>nums[mid-1]){
                    right=mid-1;
                }
                else{
                    break;
                }
            }
        }
        return nums[mid];
    }
};
// @lc code=end

