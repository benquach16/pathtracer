set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_BUILD_TYPE Debug)
set( MAKE_CXX_FLAGS "-g -Werror -Wold-style-cast -Wpedantic" )

cmake_minimum_required (VERSION 2.8.11)
project (raytracer)

set(SOURCES
    ./src/main.cpp
    ./src/rendertarget.cpp
    ./src/mesh.cpp
    )

set(DIRS
    ./src
    )

add_executable(raytracer ${SOURCES})


