#include "Service.hpp"

Service::Service():m_taskManager()
{
    std::cout<<"Service constructor"<<std::endl;
}

Service::~Service()
{
    std::cout<<"Service destructor"<<std::endl;
}

void Service::add(int a,int b)
{
    std::cout<<"add task"<< a+b << std::endl;
    if (a == 5){
        std::cout<<"number = 5"<<std::endl;
        throw std::runtime_error("error");
    }
}

int Service::mul(int a,int b,int c)
{
    std::cout<<"multi task"<<std::endl;
    return a*b*c;
}

void Service::scheduleTask()
{
    std::cout<<"Schedule Task called"<<std::endl;

    std::unordered_map<int, int> umap;

    umap[1]=1;
    umap[2]=2;
    umap[3]=3;
    umap[4]=4;
    umap[5]=5;
    umap[6]=6;

    auto func = [=](int a,int b){this->add(a,b);};

    m_taskManager.scheduleTask(func,umap);
}