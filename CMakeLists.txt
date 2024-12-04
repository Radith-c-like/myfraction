cmake_minimum_required(VERSION 3.29)
project(myfraction)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)

add_library(src STATIC src/fraction.cpp)
add_executable(myfraction_run ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)
target_link_libraries(myfraction_run PRIVATE src_lib)

add_subdirectory(googletest)