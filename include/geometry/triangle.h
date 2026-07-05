#pragma once

#include "geometry/vector.h"

vec3 subtract(vec3 a, vec3 b);
vec3 cross(vec3 a, vec3 b);
double norm(vec3 a);

double triangle_area(vec3 A, vec3 B, vec3 C);

mat2 make_columns(vec2 c1, vec2 c2);
mat2 transpose(mat2 m);
mat2 matmul(mat2 A, mat2 B);
mat2 inverse(mat2 m);

double ogden_triangle_energy(
    vec3 A, vec3 B, vec3 C,
    vec3 A0, vec3 B0, vec3 C0,
    double mu,
    double alpha
);