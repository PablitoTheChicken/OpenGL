#include "camera.h"

Camera::Camera() {
    view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
    position = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    lookDirection = glm::normalize(position - cameraTarget);
    rightDirection = glm::normalize(glm::cross(upDirection, lookDirection));
    upDirection = glm::cross(lookDirection, rightDirection);
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(position, position + lookDirection, upDirection);
}