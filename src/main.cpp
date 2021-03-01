#include "mesh.h"
#include "rendertarget.h"
#include <iostream>

using namespace std;

int main() {
  Mesh mesh;
  mesh.load("assets/monkey.obj");

  return 0;
}
