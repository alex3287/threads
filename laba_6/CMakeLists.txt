cmake_minimum_required(VERSION 3.19)
project(laba_6)

set(CMAKE_CXX_STANDARD 14)

#find_package(OpenMP)
#if(OpenMP_CXX_FOUND)
#    target_link_libraries(MyTarget PUBLIC OpenMP::OpenMP_CXX)
#endif()

add_executable(laba_6 main.cpp)



find_package(OpenMP REQUIRED)
target_link_libraries(laba_6 PRIVATE OpenMP::OpenMP_CXX)