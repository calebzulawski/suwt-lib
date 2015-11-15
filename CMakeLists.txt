cmake_minimum_required(VERSION 2.8)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/Modules/")

add_subdirectory(src)