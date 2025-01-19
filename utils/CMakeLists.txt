cmake_minimum_required(VERSION 3.20)

add_library(utils_lib INTERFACE)
target_include_directories(utils_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})