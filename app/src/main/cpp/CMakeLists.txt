cmake_minimum_required(VERSION 3.10.2)

project("MyApplication2")

add_library(
        native-lib
        SHARED
        cpp_code.cpp
)

find_library(
        log-lib
        log
)

target_link_libraries(
        native-lib
        ${log-lib}
)
