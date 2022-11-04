cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cache LANGUAGES CXX)

include_directories(lfu_cache/src/include ideal_cache/src/include)

add_executable(
    lfu
    lfu_cache/src/code/main.cpp
)

add_executable(
    ideal
    ideal_cache/src/code/main.cpp
)

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

