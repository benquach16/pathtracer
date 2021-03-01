#include "ray.h"

Ray::Ray() 
{
}

Ray::Ray(const Vector3d& origin, const Vector3d& direction) : origin(origin), direction(direction)
{
}
