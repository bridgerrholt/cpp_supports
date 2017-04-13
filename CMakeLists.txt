cmake_minimum_required(VERSION 3.6)
project(brh_cpp_supports)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/brh/supports/basic_variable.cpp
        src/brh/supports/basic_variable.h
        src/brh/supports/calc_gcd.h
        src/brh/supports/calc_is_aligned.h
        src/brh/supports/calc_lcm.h
        src/brh/supports/enum_flag_set.h
        src/brh/supports/numeric_enum.h
        src/brh/supports/round_up_to_multiple.h
        src/brh/brh_supports.h)

add_library(brh_cpp_supports ${SOURCE_FILES})

add_subdirectory(tests/full_test_1)