cmake_minimum_required(VERSION 3.30)
project(a_tour_of_cpp)

# Set the C++ standard to C++20.
set(CMAKE_CXX_STANDARD 20)

# Include the utils subdirectory.
add_subdirectory(utils)

# Add the main executable and link it with the utils library.
add_executable(a_tour_of_cpp main.cpp)
target_link_libraries(a_tour_of_cpp utils_lib)
