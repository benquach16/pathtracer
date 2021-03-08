#include "tracer.h"
#include "ray.h"

Tracer::Tracer()
    : m_rendertarget(800, 600)
{
    m_mesh.load("assets/monkey.obj");
}

Vector3d color(Ray r)
{
    Vector3d unit = normalize(r.direction);
    float t = 0.5 * (unit.y + 1);
    return (1.0 - t) * Vector3d(1.0) + t * Vector3d(0.5, 0.7, 1.0);
}

void Tracer::render()
{
    Vector3d lowerleft(-2.0, -1.0, -1.0);
    Vector3d horizontal(4.0, 0.0, 0.0);
    Vector3d vertical(0.0, 2.0, 0.0);
    Vector3d origin(0, 0, 0);
    for (int j = m_rendertarget.getHeight() - 1; j >= 0; j--) {
        for (int i = 0; i < m_rendertarget.getWidth(); ++i) {
            float u = float(i) / float(m_rendertarget.getWidth());

            float v = float(j) / float(m_rendertarget.getHeight());
            Ray r(origin, lowerleft + u * horizontal + v * vertical);
            Vector3d col = color(r);
            m_rendertarget.set(i, j, col);
        }
    }
    m_rendertarget.dump("test2.ppm");
}
