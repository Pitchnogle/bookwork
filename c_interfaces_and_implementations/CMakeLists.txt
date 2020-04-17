# c_interfaces_and_implementations/CMakeLists.txt
#
# Usage:
# cd build
# cmake ..
# make

cmake_minimum_required(VERSION 2.8)

project(c_interfaces_and_implementations C)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

subdirs(test)
