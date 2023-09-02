cmake_minimum_required(VERSION 3.26)
project(OpenGLFun)

cmake_policy(SET CMP0072 NEW)
set(CMAKE_CXX_STANDARD 23)
find_package(OpenGL REQUIRED)

add_executable(OpenGLFun main.cpp
        vendor/glad.c
        vendor/glad.h
        shader.cpp
        shader.h
        camera.cpp
        camera.h
        input.cpp
        input.h
        window.cpp
        window.h
        engine.cpp
        engine.h
)
target_link_libraries(OpenGLFun glfw OpenGL::GL)