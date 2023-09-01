#pragma once

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "vendor/glm/gtc/type_ptr.hpp"

class Instance {
public:
    int uid;
    void Destroy();
    Instance();
};