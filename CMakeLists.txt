cmake_minimum_required(VERSION 3.10)

project(FEM_Cell)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(deformation
    examples/triangle/deformation.cpp
)

target_include_directories(deformation PRIVATE include)


