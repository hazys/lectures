cmake_minimum_required(VERSION 3.21)
project(lesson_9_range_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(lesson_9_range_tree main.cpp RangeTree.cpp RangeTree.h RangeOperation.cpp RangeOperation.h RangeTreeNoRec.cpp RangeTreeNoRec.h RangeTreeOperation.cpp RangeTreeOperation.h BinaryIndexedTree.cpp BinaryIndexedTree.h SparseTable.cpp SparseTable.h)
