#pragma once

#include <string>
#include <vector>

#include "math/vector3d.h"

struct Triangle {
    Vector3d a;
    Vector3d b;
    Vector3d c;
};

class Mesh {
public:
    void load(std::string filepath);

private:
    std::vector<Vector3d> m_vertices;
    std::vector<unsigned> m_indices;
    std::vector<Vector3d> m_normals;

    std::vector<Triangle> m_triangles;
};
