template <typename T>
class SharedPtr {
private:
    T* ptr_;
    std::atomic<int>* ref_count_; // 注意：多个智能指针共享同一个计数器

public:
    // 构造函数
    explicit SharedPtr(T* p = nullptr) : ptr_(p) {
        if (p) {
            ref_count_ = new int(1);
        } else {
            ref_count_ = new int(0);
        }
    }

    // 析构函数
    ~SharedPtr() {
        release();
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr& other) {
        ptr_ = other.ptr_;
        ref_count_ = other.ref_count_;
        if (ptr_) {
            (*ref_count_)++;
        }
    }

    // 拷贝赋值运算符
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release(); // 先释放旧资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            if (ptr_) {
                (*ref_count_)++;
            }
        }
        return *this;
    }

    // 重载解引用
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

private:
    void release() {
        if (ptr_ && --(*ref_count_) == 0) {
            delete ptr_;
            delete ref_count_;
            ptr_ = nullptr;
            ref_count_ = nullptr;
        }
    }
};
