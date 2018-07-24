#project name
project(hongStudy)

#cmake minimum version
cmake_minimum_required(VERSION 3.5.1)

#compiler
set(CMAKE_C_COMPILER "gcc")

#binary name
set(BIN_NAME hongStudy)

#source list
set(SRC_LIST
    ${CMAKE_SOURCE_DIR}/src/main.c
    ${CMAKE_SOURCE_DIR}/src/sort/countingSort.c
    ${CMAKE_SOURCE_DIR}/src/sort/radixSort.c
    ${CMAKE_SOURCE_DIR}/src/sort/sortMain.c
    ${CMAKE_SOURCE_DIR}/src/sort/statistics.c
    ${CMAKE_SOURCE_DIR}/src/sort/quickSort.c
)

#include files
include_directories(BIN_NAME
    ${CMAKE_SOURCE_DIR}/include
)

#make executable file
add_executable(${BIN_NAME} ${SRC_LIST})
