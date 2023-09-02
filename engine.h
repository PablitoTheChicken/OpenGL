#pragma once

#include "shader.h"
#include "camera.h"
#include "window.h"
#include "input.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "vendor/stb_image.h"

class Engine {
public:
    Engine(int screenWidth, int screenHeight, const char* title);
    void Run();
    void Clean();
private:

    int SCR_WIDTH;
    int SCR_HEIGHT;

    unsigned int VAO{};
    unsigned int VBO{};
    unsigned int EBO{};

    Window appWindow;
    Camera camera;
    Input input;
};
