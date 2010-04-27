cmake_minimum_required (VERSION 2.6)
project (cmake_example)

add_library (show lib/show.c)
include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable (example src/main.c)
target_link_libraries (example show)
