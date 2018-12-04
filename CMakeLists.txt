
cmake_minimum_required(VERSION 3.10)
project(breakout LANGUAGES CXX)

# This line lets Conan take care of setting the dependencies lib and include paths
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/conan)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")

set(UNITY_BUILD TRUE)

set(BREAKOUT_FILES
    src/breakout.cpp
    src/Object.h
    src/Object.cpp
    src/Component.h
    src/Component.cpp
    src/Util.h
    src/RenderSystem.h
    src/RenderSystem.cpp
    src/Engine.cpp
    src/Engine.h
    src/Game.cpp
    src/Game.h
    src/ObjectFactory.h
    src/ObjectFactory.cpp
    src/Clock.h
    src/Clock.cpp
	src/InputSystem.h
	src/InputSystem.cpp)

if(NOT UNITY_BUILD)
    set(BUILD_FILES ${BREAKOUT_FILES})
else(NOT UNITY_BUILD)
    set_source_files_properties(${BREAKOUT_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
    set(BUILD_FILES src/unity_build.cpp ${BREAKOUT_FILES})
endif(NOT UNITY_BUILD)

add_executable(breakout ${BUILD_FILES})

find_package(fmt)
find_package(sfml)
find_package(jsonformoderncpp)

target_link_libraries(breakout fmt::fmt sfml::sfml jsonformoderncpp::jsonformoderncpp)

target_compile_options(breakout PRIVATE "/W4" "/WX" "/D_CRT_SECURE_NO_WARNINGS")
