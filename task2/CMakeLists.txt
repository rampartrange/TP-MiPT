cmake_minimum_required(VERSION 3.10)
project(task2 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(GTest)
find_package(Threads)

include_directories(${GTEST_INCLUDE_DIRS})

execute_process(COMMAND python3 preparing.py
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_library(index STATIC A/index.cpp A/index.h)

add_subdirectory(B ${PROJECT_SOURCE_DIR}/lib)
 
add_executable(C C/main.cpp)
add_executable(CTest C/main_test.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(C library)
target_link_libraries(C index)
target_link_libraries(CTest library)
target_link_libraries(CTest "${GTEST_LIBRARIES}" Threads::Threads)
target_link_libraries(CTest index)

target_include_directories(CTest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(C PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

