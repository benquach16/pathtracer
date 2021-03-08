#pragma once

#include "math/vector3d.h"

class Ray {
public:
    Ray() {}
    Ray(const Vector3d& origin, const Vector3d& direction)
        : origin(origin)
        , direction(direction)
    {
    }

    Vector3d origin;
    Vector3d direction;
};
