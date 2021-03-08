#pragma once

#include "mesh.h"
#include "rendertarget.h"

class Tracer {
public:
    Tracer();

    void render();

private:
    Mesh m_mesh;
    RenderTarget m_rendertarget;
};
