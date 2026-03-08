#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

template <typename T>
class BlockQueue {
private:
    std::queue<T> queue_;
    std::mutex mtx_;
    std::condition_variable cv_;
    int max_size_;

public:
    BlockQueue(int size) : max_size_(size) {}

    void produce(T item) {
        std::unique_lock<std::mutex> lock(mtx_);
        // 队列满时，生产者等待
        cv_.wait(lock, [this]() { return queue_.size() < max_size_; });
        queue_.push(item);
        std::cout << "Produced. Queue size: " << queue_.size() << "\n";
        cv_.notify_all(); // 唤醒消费者
    }

    T consume() {
        std::unique_lock<std::mutex> lock(mtx_);
        // 队列空时，消费者等待
        cv_.wait(lock, [this]() { return !queue_.empty(); });
        T item = queue_.front();
        queue_.pop();
        std::cout << "Consumed. Queue size: " << queue_.size() << "\n";
        cv_.notify_all(); // 唤醒生产者
        return item;
    }
};
