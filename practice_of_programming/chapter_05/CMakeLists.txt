# practice_of_programming/chapter_05/CMakeLists.txt

# Set the include directories
include_directories(/usr/include . ${UTIL_DIR})

# Add strings
add_executable(strings strings.c ${UTIL_DIR}/util.c)

# Add vis
add_executable(vis vis.c ${UTIL_DIR}/util.c)
