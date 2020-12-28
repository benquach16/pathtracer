#pragma once

#include "math/vector3d.h"
#include <string>
#include <vector>

class RenderTarget {
public:
  RenderTarget(int width, int height);
  ~RenderTarget();
  void dump(const std::string &filepath);

private:
  int m_width;
  int m_height;

  Vector3d **data;
};