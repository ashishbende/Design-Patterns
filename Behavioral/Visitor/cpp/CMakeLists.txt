cmake_minimum_required(VERSION 3.17)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(visitor main.cpp acyclic_visitor.cpp multi_methods.cpp stdvariant.cpp)