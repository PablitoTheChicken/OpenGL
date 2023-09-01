#pragma once
#include <iostream>
#include "camera.h"

class Input {
public:
    Input(GLFWwindow* window, Camera& camera) : window(window), camera(camera) {}
    void processInput();
    void updateDeltaTime(float newDeltaTime);
private:
    GLFWwindow* window;
    Camera& camera;
    float deltaTime = 0.0f;
};
