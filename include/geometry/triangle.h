#pragma once

#include <cmath>
#include "geometry/vector.h"

inline vec3 subtract(vec3 a, vec3 b)
{
    return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}

inline vec3 cross(vec3 a, vec3 b)
{
    return vec3{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

inline double norm(vec3 a)
{
    return std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

inline double triangle_area(vec3 A, vec3 B, vec3 C)
{
    vec3 e1 = subtract(B, A);
    vec3 e2 = subtract(C, A);
    vec3 normal = cross(e1, e2);

    return 0.5 * norm(normal);
}

inline mat2 make_columns(vec2 c1, vec2 c2)
{
    return mat2 {
        c1.x, c2.x, 
        c1.y, c2.y
    };
}

mat2 transpose(mat2 m)
{
    return mat2 {
        m.m00, m.m10,
        m.m01, m.m11
    };
}

mat2 matmul(mat2 A, mat2 B)
{
    return mat2 {
        A.m00 * B.m00 + A.m01 * B.m10, A.m00 * B.m01 + A.m01 * B.m11,
        A.m10 * B.m00 + A.m11 * B.m10, A.m10 * B.m01 + A.m11 * B.m11
    };
}
