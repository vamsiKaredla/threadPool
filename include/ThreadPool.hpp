#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#define MAX_NO_OF_THREAD 3
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>


class ThreadPool{
public:
    ThreadPool();
    ~ThreadPool();
    void wait(std::promise<void> p);

    void add_task_to_queue(std::function<void()> fn)
    {
        m_queue.push(fn);
    }

    int init();

    void executeTasks();

    std::queue<std::function<void()>> m_queue;
private:
    std::vector<std::thread> m_thread;
    std::condition_variable m_convar;
    std::mutex m_mutex;
    std::promise<void> p;
    std::future<void> f;
    bool m_execTask = false;
};
#endif