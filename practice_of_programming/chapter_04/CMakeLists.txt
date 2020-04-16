# practice_of_programming/chapter_04/CMakeLists.txt

cmake_minimum_required (VERSION 2.8)

# Set the include directories
include_directories(/usr/include .)

# Add the csv test
add_executable(csv_test csv_test.c csv.c)
