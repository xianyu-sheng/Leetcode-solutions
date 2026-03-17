class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        /*
            这里的转化：暗含了两个顺序必须是一致的  那么这样就变简单了一些
            那么剩下的问题就是，如果给你总共maxCost的预算，你可以使用一个滑动窗口来维护
            进入窗口就来减预算 出窗口 将当前的预算值增加 动态更新 或者说只要目前的预算还没有<0  那么就可以一直的增加窗口的长度
        */
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
            maxCost-=abs(s[right]-t[right]);
            //如果此时的cost 小于 0 了 那么就移动left
            while(maxCost<0){
                maxCost+=abs(s[left]-t[left]);
                left++;
            }
            //最后更新最大长度
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
