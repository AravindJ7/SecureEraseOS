cmake_minimum_required(VERSION 3.16)

project(SecureEraseOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    secureos

    src/main.cpp
    src/core/Application.cpp
)