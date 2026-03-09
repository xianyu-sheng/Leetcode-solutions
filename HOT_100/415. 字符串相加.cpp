class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry=0;//进位
        string ans="";
        //这里模拟竖式相加法 只要还有字符没有处理完 或者是还有进位就继续循环
        while(i>=0 || j>=0 || carry!=0){
            //如果指针已经越界 那么就把其当做0来处理
            int x=(i>=0)?num1[i]-'0':0;
            int y=(j>=0)?num2[j]-'0':0;

            int sum=x+y+carry;
            //将当前位追加到字符中
            ans.push_back('0'+sum%10);
            //更新进位
            carry=sum/10;
            //指针迁移
            i--;j--;
        }
        //最后翻转ans
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
