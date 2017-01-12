cmake_minimum_required(VERSION 2.8.4)
project(LFU)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lfu.cpp lfu.h ItemNodes.cpp ItemNodes.h FrequencyNode.cpp FrequencyNode.h)
add_executable(dbsg ${SOURCE_FILES})