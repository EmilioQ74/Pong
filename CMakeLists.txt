cmake_minimum_required(VERSION 3.10.0)
project(PingPong VERSION 0.1.0 LANGUAGES C CXX)

#Find OpenGL
find_package(OpenGL REQUIRED)

set(SOUND_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sound")
add_definitions(-DSOUND_DIR="${SOUND_DIR}")

#Include headers and sources
file(GLOB_RECURSE HEADERS "headers/*.h")
file(GLOB_RECURSE SOURCES "src/*")

add_executable(PingPong main.cpp ${SOURCES})
target_include_directories(PingPong PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

#Link the libraries that we need for OpenGL
target_link_libraries(PingPong PRIVATE freeglut ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} winmm)


