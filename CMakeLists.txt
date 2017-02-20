cmake_minimum_required(VERSION 2.8.4)
project(LFU)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES bin/Lfu.cpp bin/LfuTest.cpp)
add_executable(LFU ${SOURCE_FILES})
LINK_LIBRARIES(LFU cppunit)
