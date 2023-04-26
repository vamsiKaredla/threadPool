add_executable(threadPool main.cpp
                          TaskManager.cpp
                          ThreadPool.cpp
                          Service.cpp)

target_include_directories(threadPool PUBLIC ../include)
