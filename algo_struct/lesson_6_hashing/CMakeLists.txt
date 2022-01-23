cmake_minimum_required(VERSION 3.21)
project(lesson_6_hashing)
set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR /usr/include/boost)
set(Boost_LIBRARY_DIR /usr/lib/boost)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(lesson_6_hashing main.cpp utils.h utils.cpp HashList.cpp HashList.h RandomHashFunction.cpp RandomHashFunction.h HashOpenAddressing.cpp HashOpenAddressing.h CuckooHashing.cpp CuckooHashing.h BloomFilter.cpp BloomFilter.h MurmurHash3.h MurmurHash3.cpp)
