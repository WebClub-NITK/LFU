cmake_minimum_required(VERSION 2.8.4)
project(LFU)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcppunit")
set(SOURCE_FILES bin/Lfu.cpp bin/FrequencyList.cpp bin/LfuTest.cpp)
add_executable(LFU ${SOURCE_FILES})
target_link_libraries  (LFU cppunit)
