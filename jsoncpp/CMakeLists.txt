cmake_minimum_required(VERSION 2.8.4)

aux_source_directory(. SRC_LISTS)

message("Lists jsoncpp sources...")
foreach(f ${SRC_LISTS})
    message("\t${f}")
endforeach(f)

add_library(jsoncpp ${SRC_LISTS})

