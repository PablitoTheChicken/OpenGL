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
    void pollEvents();
    void swapBuffers();

private:
    GLFWwindow* window;
    int width, height;
    const char *title;

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

};
