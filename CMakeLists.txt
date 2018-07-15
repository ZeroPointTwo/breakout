
cmake_minimum_required(VERSION 3.10)
project(breakout LANGUAGES CXX)

# This line lets Conan take care of setting the dependencies lib and include paths
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")

add_executable(breakout 
	src/breakout.cpp 
	src/custom_assert.cpp)

target_include_directories(breakout
	PRIVATE "inc")

find_package(sdl2)
find_package(fmt)
target_link_libraries(breakout sdl2::sdl2 fmt::fmt)

#message(STATUS "Bin Dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#get_target_property(runtime_dir breakout CMAKE_RUNTIME_OUTPUT_DIRECTORY)
#message(STATUS "Runtime Dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

