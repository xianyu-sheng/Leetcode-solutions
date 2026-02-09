//我的思路
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        /*
            解析：这个题目的要求翻译过来就是 保证在顺序不变以及不重叠的情况下 将空间的利用最大化  尽可能的留出两个会议之间的间隔时间
            这个题也是需要想获得最大点数的那个题一样转换思路：我们不去看会议 我们来看这n+1个空闲 通过移动相邻的空闲时间 来看最大能够拼接的空余时间 注意这里的窗口应该是k+1 因为移动一个空闲时间，实际上是两个空闲时间的拼接
        */
        //先统计空闲时间
        vector<int> idle;//每个会议不重叠因此这里我直接计算每个空闲时间的长度
        int n=startTime.size();
        //首段存入
        idle.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            int len=startTime[i]-endTime[i-1];
            idle.push_back(len);
        }
        //尾部存入
        idle.push_back(eventTime-endTime[n-1]);
        //然后来看最大的空闲时间窗口
        int len=k+1;
        int sum=0,ans=0;
        for(int i=0;i<idle.size();i++){
            sum+=idle[i];
            if(i-len+1<0)   continue;
            ans=max(ans,sum);
            sum-=idle[i-len+1];
        }
        return ans;
    }
};
//灵神的空间优化版本思路
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        auto get = [&](int i) -> int {
            if (i == 0) {
                return startTime[0]; // 最左边的空余时间段
            }
            if (i == n) {
                return eventTime - endTime[n - 1]; // 最右边的空余时间段
            }
            return startTime[i] - endTime[i - 1]; // 中间的空余时间段
        };

        int s = 0, ans = 0;
        for (int i = 0; i <= n; i++) {
            s += get(i);
            if (i < k) {
                continue;
            }
            ans = max(ans, s);
            s -= get(i - k);
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/solutions/3061619/zhuan-huan-cheng-ding-chang-hua-dong-chu-1kg1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
