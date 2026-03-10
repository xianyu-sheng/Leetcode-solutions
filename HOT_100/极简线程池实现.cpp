#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional> // 用于std::function

// 极简线程池类
class ThreadPool {
private:
    // 工作线程数组
    std::vector<std::thread> workers;
    // 任务队列（存储无返回值的可调用对象）
    std::queue<std::function<void()>> tasks;
    
    // 线程同步原语
    std::mutex mtx;                  // 保护任务队列的互斥锁
    std::condition_variable cv;      // 唤醒工作线程的条件变量
    bool stop = false;               // 线程池停止标志

    // 工作线程的核心循环：不断取任务执行
    void workerLoop() {
        while (true) {
            std::function<void()> task; // 存储取出的任务

            // 加锁访问任务队列
            {
                std::unique_lock<std::mutex> lock(mtx);
                // 等待条件：要么有任务，要么线程池停止
                cv.wait(lock, [this]() { return stop || !tasks.empty(); });

                // 线程池停止且无任务 → 退出线程
                if (stop && tasks.empty()) return;

                // 取出队列头部的任务
                task = std::move(tasks.front());
                tasks.pop();
            }

            // 解锁后执行任务（避免任务执行时占用锁）
            task();
        }
    }

public:
    // 构造函数：初始化指定数量的工作线程
    explicit ThreadPool(size_t threadNum = 4) {
        for (size_t i = 0; i < threadNum; ++i) {
            workers.emplace_back(&ThreadPool::workerLoop, this);
        }
    }

    // 析构函数：优雅停止线程池
    ~ThreadPool() {
        // 加锁设置停止标志
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }
        // 唤醒所有等待的工作线程
        cv.notify_all();
        // 等待所有线程执行完毕
        for (std::thread& worker : workers) {
            worker.join();
        }
    }

    // 提交任务到线程池（支持任意参数的函数/lambda）
    template<class F>
    void submit(F&& f) {
        // 加锁将任务加入队列
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.emplace(std::forward<F>(f)); // 完美转发，减少拷贝
        }
        // 唤醒一个空闲的工作线程执行任务
        cv.notify_one();
    }

    // 禁用拷贝和移动（线程池不允许复制）
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
};

// -------------------------- 测试代码 --------------------------
int main() {
    // 创建包含2个工作线程的线程池
    ThreadPool pool(2);

    // 提交10个测试任务
    for (int i = 0; i < 10; ++i) {
        pool.submit([i]() {
            std::cout << "任务" << i << " 由线程 " << std::this_thread::get_id() << " 执行\n";
            // 模拟任务耗时
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }

    // 主线程等待所有任务执行（也可依赖析构函数自动等待）
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}
