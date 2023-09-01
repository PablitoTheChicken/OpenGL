#include "camera.h"

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    LookVector = glm::normalize(front);
    RightVector = glm::normalize(glm::cross(LookVector, WorldUpVector));
    UpVector    = glm::normalize(glm::cross(RightVector, LookVector));
}

void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw   += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += LookVector * velocity;
    if (direction == BACKWARD)
        Position -= LookVector * velocity;
    if (direction == LEFT)
        Position -= RightVector * velocity;
    if (direction == RIGHT)
        Position += RightVector * velocity;
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(Position, Position + LookVector, UpVector);
}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : LookVector(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = position;
    WorldUpVector = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}
