#include "Service.hpp"

int main()
{
    std::cout<<"beginning of implementing thread pool"<<std::endl;

    Service service;
    int num;
    service.scheduleTask();
    std::cout<<"press enter to exit"<<std::endl;
    std::cin>>num;
}