cmake_minimum_required(VERSION 3.21)
project(lesson_5_disjoint_set)

set(CMAKE_CXX_STANDARD 14)

add_executable(lesson_5_disjoint_set main.cpp DisjointSetArray.cpp DisjointSetArray.h DisjointSetTree.cpp DisjointSetTree.h)
