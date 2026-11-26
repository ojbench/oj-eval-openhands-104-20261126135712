cmake_minimum_required(VERSION 3.10)
project(problem_104 C)

add_executable(code solution.c)
set_target_properties(code PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
