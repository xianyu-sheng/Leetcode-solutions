class Solution {
public:
    int minOperations(string s) {
        /*
            该题一共分为五种情况：
            1.返回0  如果字符串本来就是排好的 什么都不用干 返回0次
            2.返回-1 这是应对于本来有序 但是一次又不能拿走所有的字符来排序的情况
            3.返回1 这是比如恰好左边的那个字符就是最低的 然后后面的大于一个字符 直接拿取后面的所有字符来排序就OK
            4.返回3 这个情况是什么？最大的字符，卡在最左边 最小的字符卡在最右边 此时就需要3次才能够将他们排序好 比如'cba'
            5.除此之外的其他情况，就需要返回2次  你先将前面的n-1抽出来进行排序 然后在将后面的n-1个字符抽出来进行排序
        */
        int n=s.length();
        string sort_s=s;
        sort(sort_s.begin(),sort_s.end());

        //情况1
        if(s==sort_s)
            return 0;
        //情况2
        if(n==2)
            return -1;
        //情况3
        if(s[0]==sort_s[0] || s[n-1]==sort_s[n-1])
            return 1;
        //情况4
        char max_char=sort_s[n-1];
        char min_char=sort_s[0];
        int max_count=count(s.begin(),s.end(),max_char);
        int min_count=count(s.begin(),s.end(),min_char);
        if(s[0]==max_char&& max_count==1 && s[n-1]==min_char && min_count==1){
            return 3;
        }
        //情况5
        return 2;
    }
};©leetcode
//题目理解：https://gemini.google.com/share/3f9ac56ef6e1
