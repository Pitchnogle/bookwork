# practice_of_programming/CMakeLists.txt
#
# Usage:
# cd build
# cmake ..
# make

cmake_minimum_required (VERSION 2.8)

project (practice_of_programming C)

set(UTIL_DIR ${CMAKE_SOURCE_DIR}/util)

subdirs(chapter_02)
subdirs(chapter_03)
subdirs(chapter_04)