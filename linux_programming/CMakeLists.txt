cmake_minimum_required (VERSION 2.8)

project (linux_programming C)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

find_package(Curses REQUIRED)

# Set the include directories
include_directories(/usr/include . ${SRC_DIR} ${CURSES_INCLUDE_DIR})

# build "hello world" for ncurses 
add_executable(curses_hello ${SRC_DIR}/curses_hello.c)
target_link_libraries(curses_hello ${CURSES_LIBRARY})

# build "moveadd" for ncurses 
add_executable(curses_moveadd ${SRC_DIR}/curses_moveadd.c)
target_link_libraries(curses_moveadd ${CURSES_LIBRARY})

# build "keys" for ncurses 
add_executable(curses_keys ${SRC_DIR}/curses_keys.c)
target_link_libraries(curses_keys ${CURSES_LIBRARY})

# build "colors" for ncurses
add_executable(curses_colors ${SRC_DIR}/curses_colors.c)
target_link_libraries(curses_colors ${CURSES_LIBRARY})