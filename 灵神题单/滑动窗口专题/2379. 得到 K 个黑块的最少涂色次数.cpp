class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int opration=0;
        for(int i=0;i<blocks.size();i++){
            //1.先来检查是不是白色 如果是白色 那么就增加操作数
            if(blocks[i]=='W')  opration++;
            //2.然后再来检查有没有满足有k个长度
            if(i-k+1<0) continue;
            //3.更新最小的数值
            ans=min(ans,opration);
            //4.来检查i-k+1是不是白色 是白色在减少
            if(blocks[i-k+1]=='W')  opration--;
        }
        return ans;
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt_w = 0;
        for (int i = 0; i < k; i++) {
            cnt_w += blocks[i] & 1;
        }
        int ans = cnt_w;
        for (int i = k; i < blocks.length(); i++) {
            cnt_w += (blocks[i] & 1) - (blocks[i - k] & 1);
            ans = min(ans, cnt_w);
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/1763639/on-hua-dong-chuang-kou-by-endlesscheng-s4fx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
