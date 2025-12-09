class Solution {
public:
    //统计数字的二进制1的个数
    int Statics(int num){
        int  count=0;
        while(num){
            num=num&(num-1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        /*
            这里需要自己来进行一个双重的sort条件排序
        */
        //然后排序
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int count_a=Statics(a);
            int count_b=Statics(b);

            if(count_a==count_b)    return a<b;
            return count_a<count_b;
        });
        return arr;
    }
};