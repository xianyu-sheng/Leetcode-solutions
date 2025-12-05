/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            这个题目与卡玛网上的字符串接龙是一模一样的
            然后这里我们需要记录重庆beginword到endword的最短转换序列的单词数目  这里我们需要是通过广度优先搜索来解决这个问题
            同时维护一个map数组来记录我们的走过的长度 以及 标记我们那里是否走了已经
        */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string,int>   is_visited; //标记是否访问过
        is_visited.insert(pair<string,int>(beginWord,1));
        //然后使用一个队列来模拟走的这个过程
        queue<string>   que;
        que.push(beginWord);
        //开始模拟
        while(!que.empty()){
            string cur_word=que.front();que.pop();
            //记录目前的序列长度  
            int path_length=is_visited[cur_word];
            //然后对每一个字符进行替换
            for(int i=0;i<cur_word.size();i++){
                string new_word=cur_word;
                //对每一位上进行26个字母的依次替换 然后检查是否是等于endword的 如果不等于endword就检查是不是在wordlist中
                for(int j=0;j<26;j++){
                    new_word[i]='a'+j;
                    //然后检查
                    if(wordSet.count(new_word) && new_word==endWord)   return  path_length+1;
                    if(wordSet.count(new_word) && is_visited.find(new_word)==is_visited.end()){
                        //那么就可以加入到里面
                        is_visited.insert(pair<string,int>(new_word,path_length+1));
                        que.push(new_word);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

