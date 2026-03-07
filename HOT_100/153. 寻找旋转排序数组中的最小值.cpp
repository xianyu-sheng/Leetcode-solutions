class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
            这里可以看到的是 这里旋转之后的数组其实也是相对有序的 具体看来就是
            不管怎么旋转 比如说其前半段依然是有序的 后半段依然是有序的 并且这里的最小值就出现在分割地带
            
            然后可以发现的就是旋转数组所造成的可能一共就nums.size()-1种  然后这里我门也可以使用二分查找来解决这个问题
            相对有序

            最简单不易出错的办法就是让nums[mid]的数据不断与nums[right]作比较 如果nums[mid] < nums[right] 这说明从 mid 到 right 这一段是严格递增的。
            如果nums[mid]>nums[right]   这说明从 mid 到 right 之间发生了“断崖”（因为正常升序数组左边应该小于右边）。
        */
        int left=0,right=nums.size()-1;
        //当left==right时，循环结束 找到最小值
        while(left<right){
            int mid=left+(right-left)/2;

            if(nums[mid]<nums[right]){
                //对应情况1 
                right=mid;
            }else{
                //对应情况2
                left=mid+1;
            }
        }
        return nums[left];
    }
};
//如果题目要求求最大值  那么就使用left不断作为参考
class Solution {
public:
    int findMax(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // 【核心修改点】向上取整，防止 left = mid 时发生死循环
            int mid = left + (right - left + 1) / 2;

            if (nums[mid] > nums[left]) {
                // 左半段是递增的，最大值在 mid 或者 mid 的右边
                left = mid; 
            } else {
                // 左半段出现了断崖，最大值肯定在断崖处，即 mid 的左边
                right = mid - 1;
            }
        }

        return nums[left]; 
    }
};
//为什么这里我们的区间设计为左闭右闭区间 但是循环条件这里不是left<=right
//这会在我们的left right都指向最小值的时候 因为条件1不满足然后这里直接进入else执行语句 导致left+1 这直接错过了最小值 并且还有越界风险

/*
    当我们是找特定值的时候 一般用left<=rihgt  找到了就直接返回
    当这一题的情况时，是找边界或者极值时 通常left<right  不断的缩进范围 直到逼出最后一个元素

    总结口诀：
        为了方便记忆，你可以记住这个二分查找的经验法则：

        只要代码里出现了 right = mid（保留 mid 作为可能的结果），循环条件就必须写 while (left < right)，否则极易死循环或逻辑错误。

        如果代码里全都是 left = mid + 1 和 right = mid - 1，那么通常写 while (left <= right)。
*/
