#include "TaskManager.hpp"

TaskManager::TaskManager():m_threadPool(){
    std::cout<<"task manager construction"<<std::endl;
    m_threadPool.init();
}

TaskManager::~TaskManager() {
    std::cout<<"task manager destructor"<<std::endl;
}

void TaskManager::scheduleTask(std::function<void(int,int)> fn,std::unordered_map<int,int> numbers) {

    for(auto i=numbers.begin();i!=numbers.end();i++)
    {   std::cout<<"numbers"<<i->first<<std::endl;
        auto func = std::bind(fn,i->first,i->second);
        m_threadPool.add_task_to_queue(func);
    }
    m_threadPool.executeTasks();

}