cmake_minimum_required(VERSION 3.20)
project(task0)

set(CMAKE_CXX_STANDARD 11)


INCLUDE_DIRECTORIES(  E:/installed_CodeBlocks20/CodeBlocks20/MinGW/include )
LINK_DIRECTORIES(  E:/installed_CodeBlocks20/CodeBlocks20/MinGW/lib )

file(GLOB LIBRARIES "E:/installed_CodeBlocks20/CodeBlocks20/MinGW/lib/liballegro.dll.a"
        "E:/installed_CodeBlocks20/CodeBlocks20/MinGW/lib/liballegro_primitives.dll.a")

file(GLOB SOURCES
        "*.hpp"
        "*.h"
        "*.cpp")
message("SOURCES = ${SOURCES}")

add_executable(task0 ${SOURCES} ISerializable.cpp ISerializable.h MovableSquare.cpp MovableSquare.h)


message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(task0  ${LIBRARIES})