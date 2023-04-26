#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "TaskManager.hpp"

class Service{
public:
    Service();
    ~Service();
    void add(int a,int b);
    int mul(int a,int b,int c);
    void scheduleTask();
private:
    TaskManager m_taskManager;
};

#endif