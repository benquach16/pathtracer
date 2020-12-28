#include "rendertarget.h"
#include <iostream>

using namespace std;

RenderTarget::RenderTarget(int width, int height)
    : m_width(width), m_height(height) {
  data = new Vector3d *[width];
  for (int i = 0; i < width; ++i) {
    data[i] = new Vector3d[height];
  }
}

RenderTarget::~RenderTarget() {
  for (int i = 0; i < m_width; ++i) {
    delete data[i];
  }
  delete data;
}

void RenderTarget::dump(const std::string &filepath) {
  int nx = m_width;
  int ny = m_height;
  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  for (int j = ny - 1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      float r = float(i) / float(nx);
      float g = float(j) / float(ny);
      float b = 0.2;
      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);
      std::cout << ir << " " << ig << " " << ib << "\n";
    }
  }
}