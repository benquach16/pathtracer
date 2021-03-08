#include "rendertarget.h"
#include "ray.h"
#include <assert.h>
#include <fstream>
#include <iostream>

using namespace std;

RenderTarget::RenderTarget(int width, int height)
    : m_width(width)
    , m_height(height)
{
    m_data = new Vector3d*[width];
    for (int i = 0; i < width; ++i) {
        m_data[i] = new Vector3d[height];
    }
}

RenderTarget::~RenderTarget()
{
    for (int i = 0; i < m_width; ++i) {
        delete m_data[i];
    }
    delete m_data;
}

void RenderTarget::dump(const std::string& filepath)
{
    int nx = m_width;
    int ny = m_height;
    ofstream fs;
    fs.open(filepath);
    if (fs.good() == false) {
        assert(false);
    }
    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            Vector3d color = m_data[i][j];
            // convert to int normalized by 255
            // assume this was a floating point normalized from 0 - 1
            int r = static_cast<int>(color.x * 255.99);
            int g = static_cast<int>(color.y * 255.99);
            int b = static_cast<int>(color.z * 255.99);
            fs << r << " " << g << " " << b << "\n";
        }
    }
    fs.close();
}
