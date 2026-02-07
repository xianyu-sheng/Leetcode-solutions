class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        /*
            1.每个到达的物品可以被保留或者被丢弃--->即操作还是不操作
            2.对于第二个条件----->这里实际上是给了一个长度为w的窗口
            3.被保留的物品不能超过m个 那么这里需要用到哈希表
            4.要求最少 那么我们怎样选择？选择临近值吧
        */
        int ans=0;//需要丢弃的物品数量
        unordered_map<int,int> counts;
        vector<bool> kept(arrivals.size(),false);//记录每一天的物品是否被保留了 实现精准清退
        /*
            这里之所以需要多增加一个kept数组：设想这样一种情况，这个元素在准备加入的时候发现就
            已经达到阈值了 已经被丢弃了 当这个元素被移动到窗口的最左端准备被取出的时候 如果我们
            不进行标记，那么就可能会多减一次 将其他的没有丢弃的其他位置相同元素给减掉 但是我们其实是不应该
            减的
        */
        for(int i=0;i<arrivals.size();i++){
            //1.加入到counts 看看如果大于m次那么就准备将其丢弃
            if(counts[arrivals[i]]>=m){
                ans++;
                kept[i]=false;
            }  
            else{
                counts[arrivals[i]]++;
                kept[i]=true;
            }    
            //2.判断窗口条件是否满足
            if(i-w+1<0) continue;
            //3.移除最左端的元素
            int left=i-w+1;
            if(kept[left]){
                if (--counts[arrivals[left]] == 0) {
                    counts.erase(arrivals[left]); // 数量归零时彻底移除，节省空间
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0; i < arrivals.size(); i++) {
            int& x = arrivals[i];
            // x 进入窗口
            if (cnt[x] == m) { // x 的个数已达上限
                // 注意 x 在未来要离开窗口，但由于已经丢弃，不能在离开窗口时修改 cnt
                // 这里直接置为 0，未来离开窗口就是 cnt[0]--，不影响答案
                x = 0; // 丢弃 arrivals[i]
                ans++;
            } else {
                cnt[x]++;
            }

            // 左端点元素离开窗口，为下一个循环做准备
            int left = i + 1 - w;
            if (left >= 0) {
                cnt[arrivals[left]]--;
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-discards-to-balance-inventory/solutions/3781207/ding-chang-hua-dong-chuang-kou-pythonjav-2abe/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
