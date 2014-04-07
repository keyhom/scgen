cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

message("Configure with ${CMAKE_BUILD_TYPE} type.")

project(scgen)

set(BASE_CFLAGS "-Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${BASE_CFLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BASE_CFLAGS} -O3")

set(TARGET_DIR "${PROJECT_BINARY_DIR}/target")

add_subdirectory(src ${TARGET_DIR})

