cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp Observer.cpp Observer.h Observable.cpp Observable.h)