class MyHashMap {
private:
    //取一个质数来作为底层哈希表的大小  有效减少冲突
    static const int base=769;
    //底层数据结构：一个数组  数组里存放的是链表 链表的节点存的是{key,value}键值对
    vector<list<pair<int,int>>> data;

    //哈希函数
    static int hash(int key){
        return key%base;
    }
public:
    MyHashMap():data(base) {
        
    }
    
    void put(int key, int value) {
        int h=hash(key);
        //遍历对应的链表
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if(it->first==key){
                //如果存在责更新
                it->second=value;
                return;
            }
        }
        //否则 直接添加在链表的末尾
        data[h].push_back({key,value});
    }
    
    int get(int key) {
        int h=hash(key);
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h=hash(key);
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if(it->first==key){
                data[h].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
