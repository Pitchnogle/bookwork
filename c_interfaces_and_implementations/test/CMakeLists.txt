# c_interfaces_and_implementations/test/CMakeLists.txt

cmake_minimum_required (VERSION 2.8)

# Set the include directories
include_directories(/usr/include . ${SRC_DIR})

# Add the arith test
add_executable(arith_test arith_test.c test_util.c ${SRC_DIR}/arith.c)

# Add the stack test
add_executable(stack_test stack_test.c test_util.c ${SRC_DIR}/stack.c ${SRC_DIR}/mem.c ${SRC_DIR}/assert.c ${SRC_DIR}/except.c)
