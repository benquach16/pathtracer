#pragma once

#include <math.h>

class Vector3d {
public:
  Vector3d() : x(0.f), y(0.f), z(0.f) {}
  Vector3d(float x, float y, float z) : x(x), y(y), z(z) {}
  Vector3d(const Vector3d &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
  }
  Vector3d &operator=(const Vector3d &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }
  bool operator==(const Vector3d &rhs) {
    // do i need espilon?
    return (rhs.x == x && rhs.y == y && rhs.z == z);
  }

  float magnitude() { return std::sqrt(x * x + y * y + z * z); }

  float x;
  float y;
  float z;
};
