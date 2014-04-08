message("Compiling the source.")
#file(GLOB_RECURSE SRC_LSITS . "*")
file(GLOB SRC_LISTS . "*.cpp" "*.c")
#set(SRC_LISTS main.cpp)

foreach(f ${SRC_LISTS})
    message("\t${f}")
endforeach(f)

add_executable(${PROJECT_NAME} ${SRC_LISTS})
target_link_libraries(${PROJECT_NAME} jsoncpp)

