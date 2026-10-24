cmake_minimum_required(VERSION 3.5)
project(binary_search CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE binary_search_tests.cpp binary_search.hpp)

# create unittests
add_executable(binary-search-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-binary-search binary-search-tests)
