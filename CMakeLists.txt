cmake_minimum_required(VERSION 3.19)
project(CasCall)

set(CLIP_EXAMPLES OFF CACHE BOOL "Compile clip examples")
set(CLIP_TESTS OFF CACHE BOOL "Compile clip tests")

set(CMAKE_CXX_STANDARD 20)

add_executable(CasCall main.cpp Functions.cpp Functions.h)

add_subdirectory(clip)

target_link_libraries(CasCall clip)