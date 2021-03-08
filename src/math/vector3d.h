#pragma once

#include <math.h>

class Vector3d {
public:
    Vector3d()
        : x(0.f)
        , y(0.f)
        , z(0.f)
    {
    }
    Vector3d(float t)
        : x(t)
        , y(t)
        , z(t)
    {
    }
    Vector3d(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    Vector3d(const Vector3d& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    Vector3d& operator=(const Vector3d& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    bool operator==(const Vector3d& rhs)
    {
        // do i need espilon?
        return (rhs.x == x && rhs.y == y && rhs.z == z);
    }

    float magnitude() const { return std::sqrt(x * x + y * y + z * z); }

    float x;
    float y;
    float z;
};

inline Vector3d operator+(const Vector3d& vec, float t)
{
    return Vector3d(vec.x + t, vec.y + t, vec.z + t);
}
inline Vector3d operator-(const Vector3d& vec, float t)
{
    return Vector3d(vec.x - t, vec.y - t, vec.z - t);
}
inline Vector3d operator*(const Vector3d& vec, float t)
{
    return Vector3d(vec.x * t, vec.y * t, vec.z * t);
}
inline Vector3d operator/(const Vector3d& vec, float t)
{
    return Vector3d(vec.x / t, vec.y / t, vec.z / t);
}
inline Vector3d operator+(const Vector3d& vec1, const Vector3d& vec2)
{
    return Vector3d(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}
inline Vector3d operator-(const Vector3d& vec1, const Vector3d& vec2)
{
    return Vector3d(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}
inline Vector3d operator*(const Vector3d& vec1, const Vector3d& vec2)
{
    return Vector3d(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
}
inline Vector3d operator/(const Vector3d& vec1, const Vector3d& vec2)
{
    return Vector3d(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
}
inline Vector3d normalize(const Vector3d& vec) { return vec / vec.magnitude(); }
