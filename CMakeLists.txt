cmake_minimum_required(VERSION 3.28)

project(test_abseil LANGUAGES CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
