#include "ThreadPool.hpp"

ThreadPool::ThreadPool()
{
    std::cout<<"Thread pool constructor"<<std::endl;
}

ThreadPool::~ThreadPool()
{
    std::cout<<"Thread pool destructor"<<std::endl;
    for(int i=0;i<MAX_NO_OF_THREAD;i++)
    {
        m_thread.at(i).join();
    }
}

void ThreadPool::wait(std::promise<void> promise)
{
    std::cout<<"Thread created and running \n"<<std::this_thread::get_id()<<std::flush;
    std::unique_lock<std::mutex> ml(m_mutex);
    m_convar.wait(ml,[&] {return (this->m_execTask==false)? false:true;});
    std::cout<<"conditional variable tested \n"<<std::flush;
    ml.unlock();

    while(!m_queue.empty()){
    m_mutex.lock();
    std::cout<<"mutex lock acquired \n"<<std::flush;
    auto func = m_queue.front();
    m_queue.pop();
    m_mutex.unlock();
    try{
    func();
    }catch(...){
        
        std::cout<<"exception captured"<<std::endl;
      promise.set_exception(std::current_exception());
    }
    }

}


void ThreadPool::executeTasks()
{
    // while(!m_queue.empty()){
    //     auto func = m_queue.front();
    //     m_thread.at(0).~thread();
    //     m_queue.pop();
    // }
    std::lock_guard<std::mutex> lg(m_mutex);
    std::cout<<"notifying all threads"<<std::endl;
    m_execTask = true;
    m_convar.notify_all();

    //check for thread failure

    // bool exit = false;

    // while(!exit)
    // {
    //     try {
    //         std::cout<<"inside while loop"<<std::endl;
    //         f.get();
    //     }catch(const std::exception& e) {
    //     std::cout << "Exception from the thread: " << e.what() << '\n';
    //     exit = true;
    // }
    // }
    // std::cout<<"waiting"<<std::endl;
    // f.wait();

    // f.;
    m_mutex.unlock();
    f.get();
}
int ThreadPool::init()
{
    std::cout<<"initializing threads"<<std::endl;
    
    f=p.get_future();

    for(int i=1; i<= MAX_NO_OF_THREAD ; i++) {
        std::thread thread(&ThreadPool::wait,this,std::move(p));
        m_thread.emplace_back(std::move(thread));
    }

    return 0;
}