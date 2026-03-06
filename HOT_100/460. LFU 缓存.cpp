struct Entry{
    int key,value,freq;//freq表示这本书被看的次数
};

class LFUCache {
private:
    int capacity;//表示容量
    int min_freq;//表示最少的访问次数
    unordered_map<int,list<Entry>::iterator> key_to_iter;//通过值O(1)的访问键
    unordered_map<int,list<Entry>> freq_to_list;//用来存储所有的数据，不同访问频次放在不同的链表

    //移动+更新频次+更新min_freq
    void move(list<Entry>::iterator it){
        Entry e=*it;
        //把这本书抽出来先
        freq_to_list[e.freq].erase(it);

        if(freq_to_list[min_freq].empty()){
            min_freq++;
        }
        e.freq++;
        freq_to_list[e.freq].emplace_front(e);//将这本书放在右边这摞书的最上面
        key_to_iter[e.key]=freq_to_list[e.freq].begin();//记录位置 更新迭代器索引
    }
public:
    LFUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        //要取这本书
        auto it=key_to_iter.find(key);
        if(it==key_to_iter.end()){
            return -1;//没这本书
        }
        //否则 有 更新频次
        int value=it->second->value;
        move(it->second);
        return value;
    }
    
    void put(int key, int value) {
        auto it=key_to_iter.find(key);
        if(it!=key_to_iter.end()){
            //有这本书 那么就需要更新器值 以及平次
            it->second->value=value;
            move(it->second);
            return;
        }

        //下面则是没有的逻辑
        if(key_to_iter.size()==capacity){
            //移除最左边那一摞书的最下面的那一本书
            auto& lst=freq_to_list[min_freq];
            key_to_iter.erase(lst.back().key);
            lst.pop_back();
        }
        freq_to_list[1].emplace_front(key,value,1);
        key_to_iter[key]=freq_to_list[1].begin();
        min_freq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
