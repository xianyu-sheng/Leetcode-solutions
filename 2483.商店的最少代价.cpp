class Solution {
public:
    int bestClosingTime(string customers) {
        /*
            解题思路：这里最重要的是需要维护一个每个时间点关门
            都需要将所有的状态统计一遍，那么这里绝对不能就是针对
            于每一个时间点都真正的单独去计算一遍全部的数组，那样
            是O(N^2)的时间复杂度，不用说直接爆炸 
            这里需要前缀和来计算 那这里是不是需要两个前缀和数组 一个维护此时关门的代价 一个维护此时开门的代价
                总代价=开门期间没客人的代价+关门期间有客人的代价
        */
        int n=customers.size();
        //前缀和  后缀和
        vector<int> prefix(n+1,0);
        vector<int> surfix(n+1,0);
        //统计前缀和---也就是对应与开门期间没有客人的代价，去找N
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+(customers[i]=='N'?1:0);
        }
        //处理后缀和  也就是处理关门期间有客人的代价
        for(int i=n-1;i>=0;i--){
            surfix[i]=surfix[i+1]+(customers[i]=='Y'?1:0);
        }

        //然后来统计
        int min_cost=INT_MAX;
        int best_hour=-1;

        for(int i=0;i<=n;i++){
            int cost=prefix[i]+surfix[i];
            if(cost<min_cost){
                min_cost=cost;
                best_hour=i;
            }
        }
        return best_hour;
    }
};

//使用O（1）的空间代价
// O(1) 空间复杂度版本
class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        // 初始代价：假设第0小时就关门，代价就是所有 'Y' 的数量
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }
        
        int min_penalty = penalty;
        int best_hour = 0;
        
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--; // 变成开门，Y的代价消除
            } else {
                penalty++; // 变成开门，N产生代价
            }
            
            // 注意：如果代价相等，因为题目要求“最早”关门时间，
            // 所以只有严格小于才更新，保持 best_hour 是较小的那个
            if (penalty < min_penalty) {
                min_penalty = penalty;
                best_hour = i + 1;
            }
        }
        return best_hour;
    }
};