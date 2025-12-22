/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            解题思路：按升序排序  并且数组中的值严格的不相同
            但是这里进行旋转了-->并且我们并不知道，然后我们需要设计一个O(log n)的算法
            首先这里旋转了，我们是不是需要先找出分界点？
            然后找到分界之后，根据分界点来我们来进一步的在两边进行二分查找，因为这里我们需要的是
            那么具体的找边界的路子可以这样

            如果mid>left那么就需要继续在右边找 
            如果mid<left那么就需要在左边找了 说明走过了
            如果mid>left  同时大于right 并且mid+1<mid了 那么就可以退出

            但是这样来解题在代码层面需要判断非常多的条件，其实我们可以想一下就是
            虽然我们进行了旋转，但是因为之前整体都是有序的 那么旋转之后的数组 其实分界点两侧都也还是有序的
            所以我们干脆就在随便找一个分界点 然后通过与left进行判断就知道在之前的前半部分还是后半部分，然后来进行查找就行
        */
        int n=nums.size();
        if(n==0)    return -1;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;

            if(nums[m]==target) return m;
            //1.如果左半侧有序
            if(nums[m]>=nums[l]){
                //target在左半侧
                if(nums[l]<=target && nums[m]>target){
                    r=m-1;
                }else{
                    l=m+1;
                }   
            }
            else{
                //如果右半侧有序
                if(target>nums[m] && target<=nums[r]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

