# practice_of_programming/chapter_02/CMakeLists.txt

cmake_minimum_required (VERSION 2.8)

# Set the include directories
include_directories(/usr/include . ${UTIL_DIR})

# Add the array examples
add_executable(example_array1 example_array1.c)
add_executable(example_array2 example_array2.c)
add_executable(example_array3 example_array3.c)

# Add the list example
add_executable(example_list example_list.c ${UTIL_DIR}/util.c)

# Add the binary tree example
add_executable(example_tree example_tree.c)

# Add the hash table example
add_executable(example_hashtable example_hashtable.c)
