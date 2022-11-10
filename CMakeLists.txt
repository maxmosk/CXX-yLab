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

target_compile_features(lfu   PUBLIC cxx_std_20)
target_compile_features(ideal PUBLIC cxx_std_20)

