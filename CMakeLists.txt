cmake_minimum_required(VERSION 3.16)
project("Bepuphysics2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
