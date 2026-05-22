cmake_minimum_required(VERSION 3.22)

project(vidocq)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_executable(vidocq ${SOURCES})
