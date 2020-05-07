# practice_of_programming/chapter_09/CMakeLists.txt

# Set the include directories
include_directories(/usr/include . ${UTIL_DIR})

# Add pack/unpack test
add_executable(pack_unpack_test pack_unpack_test.c pack_unpack.c ${UTIL_DIR}/util.c)

# Add pack/unpack example
add_executable(pack_unpack_example pack_unpack_example.c pack_unpack.c ${UTIL_DIR}/util.c)

# Add grep
add_executable(grep grep.c ${UTIL_DIR}/util.c)

# Add vm3
add_executable(vm3 vm3.c ${UTIL_DIR}/util.c)

# add expr test
add_executable(expr_test expr_test.c)

# add calc
add_executable(calc calc.c)
target_link_libraries(calc m)

# add expr
add_executable(expr expr.c)
target_link_libraries(expr m)
