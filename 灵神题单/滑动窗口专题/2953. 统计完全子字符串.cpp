class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        /*
            窗口大小一定是k的整数倍 这个题应该是需要用到不定长的滑动窗口
            那么这里如何将其转换为定长的滑动窗口呢？可以将窗口的长度划分为1-word.size()/k个长度的大小  然后再每一个窗口内来用定长滑动窗口的模板 并且满足条件
            在循环内使用哈希表来实现是不是恰好等于k每个字符
        */
        int ans=0,n=word.size();
        //外层遍历可能的窗口的长度
        for(int i=1;i<=26 && i*k<=n;i++){
            //当前遍历的窗口的长度为i*k
            int windowSize=i*k;
            int cnt[26]{};//用来统计字符出现次数
            int validCount=0;//用来统计窗口内的字符 有多少字符是满足要求1的
            int badCount=0;//用来统计有多少的相邻字符是不满足条件的
            for(int j=0;j<n;j++){
                //1.右端点进入窗口
                int right_char=word[j]-'a';
                cnt[right_char]++;
                //开始来判断右端点加入之后的情况
                if(cnt[right_char]==k)  validCount++;
                else if(cnt[right_char]==k+1)   validCount--;
                //2.然后再来检查该字符与前一个字符的差值 是不是满足条件
                if(j>0 && abs(word[j]-word[j-1])>2) badCount++;
                //3.然后检查窗口是不是够WindowsSize
                int left=j-windowSize+1;
                if(left<0)  continue;
                //4.更新逻辑
                if(validCount==i && badCount==0)    ans++;
                //5.移除左端点
                int out_char=word[left]-'a';
                if(cnt[out_char]==k)    validCount--;//移除之前是k 合法的 那么移除之后就不合法了
                cnt[out_char]--;
                if(cnt[out_char]==k)    validCount++;//原本不合法 移除之后合法
                if(left+1<n && abs(word[left+1]-word[left])>2)    badCount--;
            }
        }
        return ans;
    }
};

//灵神做法：先根据条件2分割子串 然后再在每个子串中去寻找满足条件1的字串中的子串
class Solution {
    int f(string_view s, int k) {
        int res = 0;
        for (int m = 1; m <= 26 && k * m <= s.length(); m++) {
            int cnt[26]{};
            auto check = [&]() {
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] && cnt[i] != k) {
                        return;
                    }
                }
                res++;
            };
            for (int right = 0; right < s.length(); right++) {
                cnt[s[right] - 'a']++;
                int left = right + 1 - k * m;
                if (left >= 0) {
                    check();
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }

public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        string_view s(word); // string_view 的 substr 没有拷贝
        for (int i = 0; i < n;) {
            int st = i;
            for (i++; i < n && abs(int(word[i]) - int(word[i - 1])) <= 2; i++);
            ans += f(s.substr(st, i - st), k);
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/count-complete-substrings/solutions/2551743/bao-li-hua-chuang-mei-ju-chuang-kou-nei-31j5m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
