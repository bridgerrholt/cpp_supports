cmake_minimum_required(VERSION 3.6)
project(brh_cpp_supports)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/brh/supports/basic_variable.cpp
        src/brh/supports/basic_variable.h)

add_library(brh_cpp_supports ${SOURCE_FILES})