class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0,vowel=0;
        //然后开始统计
        for(int i=0;i<s.size();i++){
            //1.右端点进
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowel++;
            }
            //开始检验
            int left=i-k+1;
            if(left<0){
                //还没达到窗口的长度为k
                continue;
            }
            //更新答案
            ans=max(ans,vowel);
            if(ans==k){
                break;
            }
            char out=s[left];
            //然后如果长度已经达到了k 那么左端点离开窗口 为下一次做准备
            if(out=='a' || out=='e' || out=='i' || out=='o' || out=='u'){
                vowel--;
            }
        }
        return  ans;
    }
};
