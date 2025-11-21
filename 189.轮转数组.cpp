/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
//暴力解法思路：超时
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            双指针法--解决问题    如何在O（N）的时间复杂度内解决问题?
            先完成一个基础版本，二重for循环来解决
        */
        int  temp=0;
        int len=nums.size()-1;
        while(k--){
            temp=nums[len];
            for(int i=len-1;i>=0;i--){
                nums[i+1]=nums[i];
            }
            nums[0]=temp;
        }
    }
};
//双指针解法思路
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            双指针法--解决问题    如何在O（N）的时间复杂度内解决问题?
            先完成一个基础版本，二重for循环来解决  --->会超时  O(N * K)  如何用一个for循环就解决呢
            可以通过将整个数组看做为两区块  然后分别现在块内做反转  然后在整体翻转 就实现了整体向右翻转的效果
        */
        int  n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            解题思路：解决办法1  先整体翻转，在局部进行翻转
        */
        int n=nums.size();
        if(n==0)    return;
        k%=n;
        reverse(nums.begin(),nums.end());
        //然后局部翻转
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
//环状数组解法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k %= n;
    if (k == 0) return;

    int count = 0;          // 已安放元素个数
    for (int start = 0; count < n; ++start) {
        int cur = start;
        int prev = nums[cur];   // 手里攥着“被挤出来”的值
        do {
            int next = (cur + k) % n;   // 目标位置
            swap(prev, nums[next]);     // prev 进去，把里面的值换出来
            cur = next;
            ++count;
        } while (cur != start);         // 回到起点说明这一圈跑完
    }
}
};
// @lc code=end

