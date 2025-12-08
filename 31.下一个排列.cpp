class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            题目理解：就是将当前的数据中的所有数据拼成一个数，然后呢？对数组里面的元素作全排列，然后来找到大于它的最小数
            如果当前元素已经是最大数了   那么就给出最小的排列
            那么这里最优先的办法当然是直接从个位开始看起 如果个位的数大于前一位就与前一位互换  这样我觉得是最接近最小差距的做法

            但是上面属于最理想的情况，我觉得一共有这样的几中情况：
            1.就是我的最后一位恰好就比前一位大  比如  1 2 3 那么我就直接交换就行   ----->1 3 2
            2.那如果我的当前位比前一位小 但是前一位又比前前一位大呢  比如  1 3 2 -->那么这时候如果在直接这样根据刚刚的进行交换 那么就会是3 1 2这样但是实际情况是我们应该得到的最小的下一个排列应该是2 1 3 这里我并没有想到更好的解法 如果进行全排列的话 那么肯定会超市的
        */
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                //记录下来当前的i-1位置 这是我们需要替换的位置
                int replace=i-1;
                //然后从后面再次遍历，选择一个比当前数据大 但大的最有限的哪个数来做替换
                for(int j=nums.size()-1;j>replace;j--){
                    if(nums[j]>nums[replace]){
                        swap(nums[replace],nums[j]);
                        break;
                    }
                }
                //然后翻转后面的  让其升序排列
                reverse(nums.begin()+replace+1,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};