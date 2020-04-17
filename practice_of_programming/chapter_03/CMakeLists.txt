# practice_of_programming/chapter_03/CMakeLists.txt

cmake_minimum_required (VERSION 2.8)

# Set the include directories
include_directories(/usr/include . ${UTIL_DIR})

# Add the markov chain example
add_executable(markov markov.c ${UTIL_DIR}/util.c)
