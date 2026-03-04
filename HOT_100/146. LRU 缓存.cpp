//手搓双向链表版-参考灵神
struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int x=0,int y=0):key(x),value(y){}
};

class LRUCache {
private:
    int cap;
    Node* dummy;
    unordered_map<int,Node*> key_to_node;

    //删除一个节点
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    //在链表头部添加一个节点
    void push_front(Node* node){
        node->prev=dummy;
        node->next=dummy->next;
        node->prev->next=node;
        node->next->prev=node;
    }

    //获取key对应的节点 同时把该节点移到链表头部
    Node* get_node(int key){
        //首先从map里获取这个节点的指针
        auto it=key_to_node.find(key);
        if(it==key_to_node.end()){
            //没有这本书
            return nullptr;
        }
        Node* node=it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    //总结：题目要求使用O(1)操作来实现get() and put() 这可以使用双向链表来实现
    //但是双向链表虽然插入和删除、查看这个值是O(1)的 但是找到这个节点的位置是O(n)的 因此这里还需要使用哈希表来存储每一个key在双向链表中的位置
    
    LRUCache(int capacity):cap(capacity),dummy(new Node()) {
        //正整数初始化LRU缓存
        dummy->next=dummy;
        dummy->prev=dummy;
    }
    
    int get(int key) {
        //如果关键字存在于缓存中，那么就返回 否则返回-1
        Node* node=get_node(key);
        return node?node->value:-1;
    }
    
    void put(int key, int value) {
        /*
            1.存在这个关键字 那么就变更数据
            2.没有存在这个关键字
                2.1 如果加进去导致关键字的数量超过了capacity 则应该逐出最近未使用的关键字
        */
        //先找是不是有
        Node* node=get_node(key);
        if(node){
            //有这本书  那么就更新
            //先将这本书移除来  放在队列头部
            remove(node);
            push_front(node);
            //然后在更新
            node->value=value;
            return;
        }
        //如果是没有 新书
        key_to_node[key]=node=new Node(key,value);
        push_front(node);
        //然后在检查是否是越界了
        if(key_to_node.size()>cap){
            Node* back_node=dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//标准库实现
class LRUCache {
public:
    //定义放在链表中的结构
    struct node{
        int key;
        int value;
    };
    std::list<node> my_list;
    std::unordered_map<int,std::list<node>::iterator> maps;
    int cap=0;//缓存的最大容量
    LRUCache(int capacity) {
        if(capacity > 0)    cap=capacity;
    }
    
    int get(int key) {
        //1.先看看是不是在缓存中
        if(maps.find(key)==maps.end()){
            return -1;
        }
        //2.如果key存在  说明被访问了 先将其提拔到队列头部
        //使用splice函数 将my_list中maps[key]指向的节点剪切并移动到my_list的头部
        //splice是O(1)的操作，只修改指针，不涉及内存拷贝
        my_list.splice(my_list.begin(),my_list,maps[key]);
        //3.返回该节点的值
        return maps[key]->value;
    }
    
    void put(int key, int value) {
        //1.情况1 key已经存在
        if(maps.find(key)!=maps.end()){
            //那么就更新 先将其提拔到队列头部
            maps[key]->value=value;
            my_list.splice(my_list.begin(),my_list,maps[key]);
            return;
        }
        //2.节点不存在 需要插入新节点
        //先检查容量
        if(my_list.size()==cap){
            //这里注意的是，我们需要先删map里的记录 然后再来删list的节点  
            //因为我们需要通过list.back()来查看我们需要删谁
            int key_to_remove=my_list.back().key;
            maps.erase(key_to_remove);
            my_list.pop_back();
        }
        //然后在将节点插入到链表头部
        my_list.push_front({key,value});
        maps[key]=my_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
