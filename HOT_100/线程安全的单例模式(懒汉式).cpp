class Singleton {
public:
    // 获取全局唯一实例
    static Singleton& getInstance() {
        static Singleton instance; // C++11 起保证线程安全
        return instance;
    }

    // 禁用拷贝构造和赋值操作符，防止产生多个实例
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // 私有化构造和析构函数
    Singleton() {
        // 初始化资源
    }
    ~Singleton() = default;
};
