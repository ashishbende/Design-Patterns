cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src event_broker.cpp creature_example.cpp)