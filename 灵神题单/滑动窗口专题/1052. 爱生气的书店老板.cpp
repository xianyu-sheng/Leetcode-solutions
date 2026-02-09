class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //如果使用了minutes那么肯定是需要在尽量多的生气的情况下使用 然后这里使用了 那么这段时间的顾客就是满意的
        //然后除了使用minutes的这部分时间，其他不生气的时间也应该计算上
        //因此这里就需要转换一下逻辑 即我们需要找到生气最多的那个区间&&客流量的最大的区间 然后在将其与其他的不生气的时候加上
        //转换一下思路先算出不生气时候的满意度 然后在来算如果使用技巧 最大能够收获的额外的满意度
        int basic_ans=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)
                basic_ans+=customers[i];
        }
        //然后现在再来计算额外的满意度
        int extra_ans=0;
        int current_ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==1){
                current_ans+=customers[i];
            }
            //如果不够一个窗口 那就继续
            if(i-minutes+1<0)   continue;
            //更新最大的额外满意度
            extra_ans=max(extra_ans,current_ans);
            //弹出左端值
            if(grumpy[i-minutes+1]==1)  current_ans-=customers[i-minutes+1];
        }
        return basic_ans+extra_ans;
    }
};

//灵神解法
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2]{}, max_s1 = 0;
        for (int i = 0; i < customers.size(); i++) {
            s[grumpy[i]] += customers[i];
            int left = i - minutes + 1; // 窗口左端点
            if (left < 0) { // 窗口长度不足 minutes
                continue;
            }
            max_s1 = max(max_s1, s[1]);
            // 窗口最左边元素离开窗口
            s[1] -= grumpy[left] ? customers[left] : 0;
        }
        return s[0] + max_s1;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/grumpy-bookstore-owner/solutions/2751888/ding-chang-hua-dong-chuang-kou-fu-ti-dan-rch7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
