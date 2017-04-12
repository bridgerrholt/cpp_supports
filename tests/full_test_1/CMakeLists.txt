cmake_minimum_required(VERSION 3.6)
project(full_test_1)

set(CMAKE_CXX_STANDARD 14)

link_libraries(brh_cpp_supports)

add_executable(full_test_1 main.cpp)

target_include_directories(full_test_1 PUBLIC ../../src/brh)