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
        "*.cpp"
        "Exceptions/*.hpp"
        "Exceptions/*.cpp"
        "Figures/*.hpp"
        "Figures/*.cpp"
        "Interfaces/*.hpp"
        "Interfaces/*.cpp"
        "Factories/*.hpp"
        "Factories/*.cpp"
        "Allegro/*.hpp"
        "Allegro/*.cpp"
        )
message("SOURCES = ${SOURCES}")


add_executable(task0 ${SOURCES} Exceptions/EDivide.cpp Exceptions/EDivide.h Exceptions/EHit.cpp Exceptions/EHit.h Exceptions/EHitBoth.cpp Exceptions/EHitBoth.h Point.h Exceptions/EFigureDeath.cpp Exceptions/EFigureDeath.h)


message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(task0  ${LIBRARIES})