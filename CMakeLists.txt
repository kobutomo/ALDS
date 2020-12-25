#cmake_minimum_required(VERSION 3.14)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

# Contest abc 130
add_executable(ALDS1_Stack_main ALDS1_Stack/main.cpp)
add_executable(ALDS1_Stack_test ALDS1_Stack/test.cpp)

add_executable(ALDS1_Allocation_main ALDS1_Allocation/main.cpp)
add_executable(ALDS1_Allocation_test ALDS1_Allocation/test.cpp)

add_executable(ALDS1_Exhaustive_Search_main ALDS1_Exhaustive_Search/main.cpp)
add_executable(ALDS1_Exhaustive_Search_test ALDS1_Exhaustive_Search/test.cpp)

add_executable(ALDS1_Koch_Curve ALDS1_Koch_Curve/main.cpp)

add_executable(ALDS_Merge_Sort ALDS_Merge_Sort/main.cpp)

add_executable(ALDS_Partition ALDS_Partition/main.cpp)

add_executable(ALDS_Quick_Sort ALDS_Quick_Sort/main.cpp)

add_executable(ALDS_Counting_Sort ALDS_Counting_Sort/main.cpp)
