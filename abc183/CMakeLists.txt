project(abc183)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall")
set(CMAKE_CXX_STANDARD 17)
find_package(BOOST)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(abc183a a.cpp)
add_executable(abc183b b.cpp)
add_executable(abc183c c.cpp)
add_executable(abc183d d.cpp)
add_executable(abc183e e.cpp)
add_executable(abc183f f.cpp)
