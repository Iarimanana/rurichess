cmake_minimum_required(VERSION 4.2)
project(rurichess)
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_CXX_STANDARD 20)