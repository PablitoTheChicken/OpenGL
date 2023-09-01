#pragma once
#include "instance.h"

class Camera {
public:
    glm::vec3 position{};
    glm::vec3 cameraTarget{};
    glm::vec3 lookDirection{};
    glm::vec3 upDirection{};
    glm::vec3 rightDirection{};

    glm::mat4 view{};
    glm::mat4 projection{};

    Camera();
    glm::mat4 GetViewMatrix() const;
};
