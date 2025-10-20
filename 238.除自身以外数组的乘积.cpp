/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            解题思路：题目要求在O（n）的时间复杂度里完成这个乘积  应该怎么做呢？
            我可不可以这样呢  其实可以使用两个数来存储他们的值 一个存储前半段 一个存储后半段 
            所谓前半段怎么定义呢？---->比如此时是nums[0]那么 此时前半段的乘积就为nums[0]
            后半段的乘积就是除一之外的其余各数的乘积 
            这样做的原由我发现 比如在nums[3]的时候 还是需要0-2是乘积的 
            真正在编写代码的时候肯定就是先将前缀积与后缀乘完之后 然后在加入自己作为后一个元素的前缀积
        */

        int n=nums.size();
        vector<int> answer(n,1);
        int pre_mul=1,post_mul=1;
        for(int i=0;i<n;i++){
            answer[i]=pre_mul;
            pre_mul*=nums[i];
        }
        for(int j=n-1;j>=0;j--){
            answer[j]*=post_mul;
            post_mul*=nums[j];
        }
        return answer;
    }
};
// @lc code=end

