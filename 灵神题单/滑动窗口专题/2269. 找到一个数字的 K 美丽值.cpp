class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //将窗口内的数字摘出来 然后用n/这个数字 看能否整除
        int ans=0;
        if(k==0)    return 1;
        string str_num=to_string(num);
        //滑动窗口
        int s_num=0;
        for(int i=0;i<str_num.size();i++){
            //右端点进
            s_num=s_num*10+(str_num[i]-'0');
            //检查是否够窗口
            if(i-k+1<0) continue;
            //满足窗口条件
            if(s_num && num%s_num==0)    ans++;
            //移除左端点
            int left=i-k+1;
            s_num=s_num-(str_num[left]-'0')*pow(10,k-1);
        }
        return ans;
    }
};
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for (int i = k; i <= s.size(); i++) {
            int x = stoi(s.substr(i - k, k)); // 长为 k 的子串
            if (x > 0 && num % x == 0) { // 子串能整除 num
                ans++;
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-the-k-beauty-of-a-number/solutions/1496449/mo-ni-by-endlesscheng-burh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        const long long M = pow(10, k);
        int ans = 0;
        for (int n = num; n >= M / 10; n /= 10) {
            int x = n % M;
            if (x > 0 && num % x == 0) {
                ans++;
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-the-k-beauty-of-a-number/solutions/1496449/mo-ni-by-endlesscheng-burh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  
