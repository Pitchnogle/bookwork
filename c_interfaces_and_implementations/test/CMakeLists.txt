# c_interfaces_and_implementations/test/CMakeLists.txt

cmake_minimum_required (VERSION 2.8)

# Set the include directories
include_directories(/usr/include .)

# Add the csv test
add_executable(testme test.c ${SRC_DIR}/mem.c ${SRC_DIR}/atom.c ${SRC_DIR}/except.c ${SRC_DIR}/stack.c)
