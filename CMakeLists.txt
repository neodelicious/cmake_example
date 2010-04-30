#written by Jaewon Kim , neodelicious@gmail.com 

# project 
cmake_minimum_required (VERSION 2.6)
project (cmake_example)

# global CMAKE variables
set (BUILD_SHARED_LIBS true)
set (CMAKE_VERBOSE_MAKEFILE true)
set (CMAKE_BUILD_TYPE debug)

# global build variables
include_directories ("${PROJECT_SOURCE_DIR}/include")

# build library
add_library (show lib/show.c)

# build source
add_executable (example src/main.c)
target_link_libraries (example show)
