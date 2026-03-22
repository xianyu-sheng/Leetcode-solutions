class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnt_odd=0;
        for(int x:nums1)
            if(abs(x)%2==1)
                cnt_odd++;

        //情况1
        if(cnt_odd==0)
            return true;
        else if(cnt_odd==1)
            return true;
        else if(cnt_odd>=2)
            return true;

        return false;
    }
};©leetcode
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};©leetcode

//重点 分析奇偶性  奇数+(+-)奇数 奇数(+-)偶数得到的不同性
