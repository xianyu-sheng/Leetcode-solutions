class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        /*
            //这里的意思 我认为可以转换为这样的模型 就是说比如此时我用T来记录true的个数  F 来记录False的个数
            我们现在是需要将其转换为连续相同的一个字符 那么这里就选择较小值来选择就行了 
            那么这里我们需要将其转换为滑动窗口呢？  那就是如果比如此时 T=10 F=3 k=2  那么此时就需要移动我们的左端点了
        */
        int count_T=0,count_F=0;
        int max_len=0;
        for(int l=0,r=0;r<answerKey.size();r++){
            count_T+=(answerKey[r]=='T');
            count_F+=(answerKey[r]=='F');
            //然后此时我们再来判断是否需要移动
            while(min(count_T,count_F)>k){
                count_T-=(answerKey[l]=='T');
                count_F-=(answerKey[l]=='F');
                l++;
            }
            //更新值
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};
