#cmake minimum version
cmake_minimum_required(VERSION 3.5.1)

#compiler
set(CMAKE_C_COMPILER "gcc")

#binary name
set(BIN_NAME hongStudy)

#source list
set(SRC_LIST
    ${CMAKE_SOURCE_DIR}/main.c
)

#make executable file
add_executable(${BIN_NAME} ${SRC_LIST})
