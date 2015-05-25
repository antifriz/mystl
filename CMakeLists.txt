cmake_minimum_required(VERSION 2.8)
project(mystl)

FILE(GLOB SOURCE_FILES
src/*.cc
)

include_directories(
include
)

set(CMAKE_CXX_COMPILER g++)

add_library(mystl STATIC ${SOURCE_FILES})
