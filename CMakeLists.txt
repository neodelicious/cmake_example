#written by Jaewon Kim , neodelicious@gmail.com 

# project 
cmake_minimum_required (VERSION 2.6)
project (cmake_example)

# user selectable variables
option (ENABLE_SHARED "Select OFF to build libraries as static" ON)
option (DEBUG "Select ON to define DEBUG" ON)
option (DEBUG2 "Select ON to define DEBUG2" ON)
message ("ENABLE_SHARED - ${ENABLE_SHARED}")
message ("DEBUG - ${DEBUG}")
message ("DEBUG2 - ${DEBUG2}")

# checking dependencies
include (FindPkgConfig)
#pkg_check_modules (pkgs REQUIRED x11>=1.2.2 xrender)
pkg_check_modules (pkgs x11>=1.2.2 xrender)
foreach (flag ${pkgs_CFLAGS})
  set (EXTRA_LIBS ${EXTRA_LIBS} ${flag})
endforeach (flag)
foreach (flag ${pkgs_LDFLAGS})
  set (EXTRA_LIBS ${EXTRA_LIBS} ${flag})
endforeach (flag)

# global CMAKE variables
if (ENABLE_SHARED)
  set (BUILD_SHARED_LIBS true)
endif (ENABLE_SHARED)
set (CMAKE_VERBOSE_MAKEFILE true)
set (CMAKE_BUILD_TYPE debug)
set (CMAKE_INSTALL_PREFIX /usr)

# global build variables
include_directories ("${PROJECT_SOURCE_DIR}/include")

# variables to the configuration file
configure_file ("${PROJECT_SOURCE_DIR}/include/config.h.in" "${PROJECT_SOURCE_DIR}/include/config.h")

# build library
add_library (show lib/show.c)

# build source
add_executable (example src/main.c)
target_link_libraries (example show ${EXTRA_LIBS})

# install
install (TARGETS show DESTINATION lib)
install (TARGETS example DESTINATION bin)
install (FILES ${PROJECT_SOURCE_DIR}/include/show.h DESTINATION include)
