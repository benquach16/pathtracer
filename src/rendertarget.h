#pragma once

#include "math/vector3d.h"
#include <string>
#include <vector>

class RenderTarget {
public:
    RenderTarget(int width, int height);
    ~RenderTarget();
    void dump(const std::string& filepath);
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    void set(int x, int y, Vector3d color) { m_data[x][y] = color; }
    Vector3d get(int x, int y) const { return m_data[x][y]; }

private:
    int m_width;
    int m_height;

    Vector3d** m_data;
};
