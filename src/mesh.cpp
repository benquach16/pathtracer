#include "mesh.h"
#include "3rdparty/OBJ_Loader.h"
#include <iostream>

using namespace std;

void Mesh::load(std::string filepath) {

  objl::Loader loader;
  loader.LoadFile(filepath);
  std::cerr << "loaded file :" << filepath << " with "
            << loader.LoadedMeshes.size() << " meshes" << std::endl;

  for (int i = 0; i < loader.LoadedMeshes[0].Vertices.size(); ++i) {
    auto vert = loader.LoadedMeshes[0].Vertices[i];
    Vector3d vertex(vert.Position.X, vert.Position.Y, vert.Position.Z);
    Vector3d normal(vert.Normal.X, vert.Normal.Y, vert.Normal.Z);
    m_vertices.push_back(vertex);
    m_normals.push_back(normal);
  }

  for (auto i : loader.LoadedMeshes[0].Indices) {
    m_indices.push_back(i);
  }

  for (int i = 0; i < m_indices.size() - 2; i += 2) {
    Triangle tri;
    int aIdx = m_indices[i];
    int bIdx = m_indices[i + 1];
    int cIdx = m_indices[i + 2];

    tri.a = m_vertices[aIdx];
    tri.b = m_vertices[bIdx];
    tri.c = m_vertices[cIdx];

    m_triangles.push_back(tri);
  }

  cout << "triangles" << m_triangles.size() << endl;
}