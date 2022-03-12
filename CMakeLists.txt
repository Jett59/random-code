cmake_minimum_required(VERSION 3.10)

project(random-code LANGUAGES CXX)

add_executable(random-code src/main.cpp src/assembler.cpp)

target_include_directories(random-code PRIVATE "${PROJECT_SOURCE_DIR}/include")
