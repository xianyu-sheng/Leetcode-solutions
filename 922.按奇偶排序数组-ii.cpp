/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        /*
            解题思路：设定一个数组，与nums想等长度，循环的便利，直到每个位置填满
            搞一个n^2的解法----->不过去要求没有额外的空间  那么看来 就需要比如在一个位置本来
            应该是填入偶数的时候填的是奇数，因此我们只需要遍历一遍，把不是这个位置上的元素与另一个也本不该是这个位置的元素进行交换就行
            如果现在这个位置本该是奇数，那么我们就去偶数位找奇数元素进行交换
            如果本该是偶数，那么就去奇数位找偶数来进行交换
        */
        int  n=nums.size();
        for(int i=0;i<n;i++){
            //只进行异常情况的处理  即奇数位是偶数  那么我们就去找偶数位的奇数
            if(i%2==1 && nums[i]%2==0){
                int j=search_num(nums,i+1,0);
                swap(nums[i],nums[j]);
            }
            //偶数位是奇数，去奇数位找偶数
            if(i%2==0 && nums[i]%2==1){
                int j=search_num(nums,i+1,1);
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
    int search_num(vector<int>& nums,int start,int item){
        //item=0  代表我们过来在偶数位找奇数
        //item=1  代表我们在奇数位找偶数
        int index=-1;
        if(item==0){
            for(int i=start;i<nums.size();i++){
                if(i%2==0 && nums[i]%2==1){
                    index=i;
                    break;
                }
            }
        }
        else{
            for(int i=start;i<nums.size();i++){
                if(i%2==1 && nums[i]%2==0){
                    index=i;
                    break;
                }
            }
        }
        return index;
    }
};
// @lc code=end

