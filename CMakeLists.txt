cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

message("Configure with ${CMAKE_BUILD_TYPE} type.")

project(scgen)

set(BASE_CFLAGS "-Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${BASE_CFLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BASE_CFLAGS} -O3")

set(INCLUDE_DIR "${PROJECT_BINARY_DIR}/include")

include_directories("include")
add_subdirectory(jsoncpp "${PROJECT_BINARY_DIR}/jsoncpp")
add_subdirectory(src "${PROJECT_BINARY_DIR}/${PROJECT_NAME}")

