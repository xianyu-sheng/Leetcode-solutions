/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 *
 * [3074] 重新分装苹果
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        /*
            解题思路：这里其实就是先将我们的苹果的总数先记录下来，反正可以分开装
            然后在从箱子里挑大的装，装满一个箱子记录一下，直到sum==0
        */
        // 使用 accumulate 快速求和
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=capacity.size()-1;i>=0;i--){
            if(sum<=0)   break;
            sum-=capacity[i];
            ans++;
        }
        return ans;
    }
};
// @lc code=end

