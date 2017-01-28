cmake_minimum_required(VERSION 2.8.4)
project(LFU)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES headers/lfu.h src/ItemNodes.cpp headers/ItemNodes.h src/FrequencyNode.cpp headers/FrequencyNode.h test/LFUTest.cpp test/LFUTest.h)
add_executable(LFU ${SOURCE_FILES})
LINK_LIBRARIES(LFU cppunit)
