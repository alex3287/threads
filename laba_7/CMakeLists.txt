cmake_minimum_required(VERSION 3.19)
project(laba_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba_7 main.cpp)

find_package(OpenMP REQUIRED)
target_link_libraries(laba_7 PRIVATE OpenMP::OpenMP_CXX)