class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口+哈希表
        unordered_map<char,int> mymap;
        int n=s.length(),ans=0,left=0;
        for(int right=0;right<n;right++){
            //然后值加一 如果值大于1 则更新
            mymap[s[right]]+=1;
            while(mymap[s[right]]>1){
                //移除左端点
                mymap[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};

//让left不在一个一个的跳跃 而是一段一段的跳跃 直接跳到与当前字符冲突的字符位置的下一个
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 用数组代替哈希表记录字符最后出现的下标，初始值为 -1
        vector<int> lastOccurred(128, -1); 
        int n = s.length(), ans = 0, left = 0;
        
        for(int right = 0; right < n; right++) {
            char c = s[right];
            
            // 如果这个字符之前出现过，我们就需要更新 left 指针
            if (lastOccurred[c] != -1) {
                // 核心易错点：必须用 max，防止 left 往回倒退
                left = max(left, lastOccurred[c] + 1);
            }
            
            // 无论如何，把当前字符的最新下标记录下来
            lastOccurred[c] = right;
            
            // 计算当前窗口长度并更新结果
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
