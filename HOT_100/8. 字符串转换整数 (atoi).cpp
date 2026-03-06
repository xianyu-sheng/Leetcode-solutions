class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        int sign=1;//默认为正数
        long long res=0;//使用long long 避免中间溢出

        //1.跳过前导的空格
        while(i<n && s[i]==' ') i++;
        
        //2.处理负号
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }

        //3.读取数字
        while(i< n && s[i]<='9' && s[i]>='0'){
            int digit=s[i]-'0';

            //检查溢出  INT_MAX=2147483647
            if(res > INT_MAX/10 || (res==INT_MAX/10 && digit>7)){
                return (sign==1)?INT_MAX:INT_MIN;
            }

            res=res*10+digit;
            i++;
        }
        return res*sign;
    }
};
