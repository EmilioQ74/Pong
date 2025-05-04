cmake_minimum_required(VERSION 3.10.0)
project(PingPong VERSION 0.1.0 LANGUAGES C CXX)


#Include it to the Project
set(SOUND_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sound")
add_definitions(-DSOUND_DIR="${SOUND_DIR}")

if(MSVC)
   
    #Set the paths for the freeglut
    set(FREEGLUT_CUSTOM_PATH "${CMAKE_SOURCE_DIR}/VSfreeglut")
    
    # Find OpenGL
    find_package(OpenGL REQUIRED)
    
    # Find FreeGLUT include and library files
    find_path(GLUT_INCLUDE_DIR NAMES GL/freeglut.h
    PATHS "${FREEGLUT_CUSTOM_PATH}/include" NO_DEFAULT_PATH)

    find_library(GLUT_LIBRARIES NAMES freeglut
        PATHS "${FREEGLUT_CUSTOM_PATH}/lib/x64/" NO_DEFAULT_PATH)

    # Check if FreeGLUT was found
    if (GLUT_INCLUDE_DIR AND GLUT_LIBRARIES)
        message(STATUS "Found FreeGLUT in custom path.")
        set(GLUT_FOUND TRUE)
    else()
        message(FATAL_ERROR "FreeGLUT not found in system or custom path.")
    endif()
elseif(MINGW)
    message(STATUS "Using MinGW compiler")
    # Find OpenGL
    find_package(OpenGL REQUIRED)
    find_package(GLUT QUIET)
    if(NOT GLUT_FOUND)
        message(FATAL_ERROR "FreeGLUT not found in system or custom path.")
        message(("Please install freeglut-dev package by msys2 package manager")) 
    endif()
    # Add any specific MinGW configuration here
else()
    message(FATAL_ERROR "Unsupported compiler. This project supports only MSVC or MinGW.")
endif()

#Including header and src to the project
file(GLOB_RECURSE HEADERS "headers/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

#Compiles the main and the src folder
add_executable(PingPong main.cpp ${SOURCES})
#Links the headers no need for include "../smth" only "smth"
target_include_directories(PingPong PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Include FreeGLUT headers from either system or fallback
if(MSVC)
    target_include_directories(PingPong PRIVATE "${FREEGLUT_CUSTOM_PATH}/include")
endif()
#Link the libraries that we need for OpenGL
target_link_libraries(PingPong PRIVATE ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} winmm)

if(MINGW)
target_link_libraries(PingPong PRIVATE freeglut)
endif()

if(MSVC)
    target_link_libraries(PingPong PRIVATE "${FREEGLUT_CUSTOM_PATH}/lib/x64/freeglut.lib")
    add_custom_command(TARGET PingPong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FREEGLUT_CUSTOM_PATH}/bin/freeglut.dll"
        $<TARGET_FILE_DIR:PingPong>)
endif()