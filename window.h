#pragma once
#include "vendor/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    GLFWwindow* getWindow();
    bool shouldClose();
    static void pollEvents();
    void swapBuffers();

private:
    GLFWwindow* window;
    int width, height;
    const char *title;

    static void framebufferSizeCallback(GLFWwindow* window, int m_width, int m_height) {
        glViewport(0, 0, m_width, m_height);
    }

};