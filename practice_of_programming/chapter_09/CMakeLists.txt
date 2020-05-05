# practice_of_programming/chapter_09/CMakeLists.txt

# Set the include directories
include_directories(/usr/include . ${UTIL_DIR})

# Add pack/unpack test
add_executable(pack_unpack_test pack_unpack_test.c pack_unpack.c ${UTIL_DIR}/util.c)
