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
