cmake_minimum_required(VERSION 3.28)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)

set(TARGET_NAME advent_of_code)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${TARGET_NAME} ${SOURCE_FILES})

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/public_include)
