#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "ThreadPool.hpp"
#include <unordered_map>

class TaskManager {

public:
    TaskManager();
    ~TaskManager();

    void scheduleTask(std::function<void(int,int)>,std::unordered_map<int,int> numbers);

    // template<typename Func, typename... Args>
    // void scheduleTask(Func fn,Service& service,Args... args,std::unordered_map<int,int> numbers);
private:
   ThreadPool m_threadPool;
};

#endif