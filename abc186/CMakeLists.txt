project(abc186)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall")
set(CMAKE_CXX_STANDARD 17)
find_package(BOOST)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(abc186a a.cpp)
add_executable(abc186b b.cpp)
add_executable(abc186c c.cpp)
add_executable(abc186d d.cpp)
add_executable(abc186e e.cpp)
add_executable(abc186f f.cpp)
