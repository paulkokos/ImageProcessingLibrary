cmake_minimum_required(VERSION 3.6)
project(ImageProcessingLibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(main ${SOURCE_FILES} src/main.cpp src/ImageProcessing.cpp src/ImageProcessing.hpp)
add_subdirectory(libs)

SET(CMAKE_CXX_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")




