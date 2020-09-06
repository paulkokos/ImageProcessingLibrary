cmake_minimum_required(VERSION 3.6)
project(ImageProcessingLibrary)

set(CMAKE_CXX_STANDARD 20)

#set(SOURCE_FILES StandardLibraryHeaders/UtilitiesLibrary/variant/variant/variant.cpp)
add_executable(main ${SOURCE_FILES}main.cpp ImageProcessing.cpp ImageProcessing.hpp)
#add_subdirectory(AlgorithmsLibrary)
#add_subdirectory(ThreadSupportLibrary)
SET(CMAKE_CXX_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
