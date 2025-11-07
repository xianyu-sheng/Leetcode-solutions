#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
/*
    解题思路：将这个字符串迁移看做是一个图，然后中间部分应该全都是strlist中的元素 然后在最短的连通子路
    其中，beginstr就是起点  endstr就是终点
*/
int main(){
    int N;  //strlist中的元素个数
    cin >> N;
    string beginstr,endstr,str;
    cin >> beginstr >> endstr;
    unordered_set<string> strList;
    for(int i=0;i<N;i++){
        cin >> str;
        strList.insert(str);
    }

    //记录strList中的元素是否被访问过 同时记录路径长度
    unordered_map<string,int> visitmap;

    //初始化队列 使用广度优先搜索
    queue<string> que;
    que.push(beginstr);
    visitmap.insert(pair<string,int>(beginstr,1));

    //广度优先搜索
    while(!que.empty()){
        string  word=que.front();
        que.pop();
        int path=visitmap[word];

        //然后开始搭建图 对每一位进行26个字母的替换 看看是否出现在strList中
        for(int i=0;i<word.size();i++){
            string newword=word;
            for(int k=0;k<26;k++){
                newword[i]=k+'a';
                //如果已经等于endword 那么就输出
                if(newword==endstr){
                    cout << path+1 <<endl;
                    return 0;
                }
               //否则就是 字符串集合里面有 但是还没有访问过这个元素
               if(strList.find(newword)!=strList.end() && visitmap.find(newword)==visitmap.end()){
                    que.push(newword);
                    visitmap[newword]=path+1;
               } 
            }
        }
    }
    return 0;
}