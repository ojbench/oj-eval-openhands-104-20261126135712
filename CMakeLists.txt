cmake_minimum_required(VERSION 3.10)
project(problem_104 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code solution.cpp)

# Ensure the output binary is in the current directory
set_target_properties(code PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
