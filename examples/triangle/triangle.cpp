#include "geometry/triangle.h"

#include <cmath>
#include <stdexcept>

vec3 subtract(vec3 a, vec3 b)
{
    return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 cross(vec3 a, vec3 b)
{
    return vec3{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

double norm(vec3 a)
{
    return std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

double triangle_area(vec3 A, vec3 B, vec3 C)
{
    vec3 e1 = subtract(B, A);
    vec3 e2 = subtract(C, A);
    vec3 normal = cross(e1, e2);

    return 0.5 * norm(normal);
}

mat2 make_columns(vec2 c1, vec2 c2)
{
    return mat2{
        c1.x, c2.x,
        c1.y, c2.y
    };
}

mat2 transpose(mat2 m)
{
    return mat2{
        m.m00, m.m10,
        m.m01, m.m11
    };
}

mat2 matmul(mat2 A, mat2 B)
{
    return mat2{
        A.m00*B.m00 + A.m01*B.m10,
        A.m00*B.m01 + A.m01*B.m11,
        A.m10*B.m00 + A.m11*B.m10,
        A.m10*B.m01 + A.m11*B.m11
    };
}

mat2 inverse(mat2 m)
{
    double det = m.m00*m.m11 - m.m01*m.m10;

    if (std::abs(det) < 1e-12)
    {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }

    double inv_det = 1.0 / det;

    return mat2{
         m.m11 * inv_det, -m.m01 * inv_det,
        -m.m10 * inv_det,  m.m00 * inv_det
    };
}

double ogden_triangle_energy(
    vec3 A, vec3 B, vec3 C,
    vec3 A0, vec3 B0, vec3 C0,
    double mu,
    double alpha
)
{
    double area0 = triangle_area(A0, B0, C0);

    vec3 E1 = subtract(B0, A0);
    vec3 E2 = subtract(C0, A0);

    vec3 e1 = subtract(B, A);
    vec3 e2 = subtract(C, A);

    vec2 E1_2d{E1.x, E1.y};
    vec2 E2_2d{E2.x, E2.y};

    vec2 e1_2d{e1.x, e1.y};
    vec2 e2_2d{e2.x, e2.y};

    mat2 D0 = make_columns(E1_2d, E2_2d);
    mat2 D  = make_columns(e1_2d, e2_2d);

    mat2 F = matmul(D, inverse(D0));
    mat2 C_tensor = matmul(transpose(F), F);

    double trace = C_tensor.m00 + C_tensor.m11;
    double det = C_tensor.m00*C_tensor.m11 - C_tensor.m01*C_tensor.m10;

    double discriminant = trace*trace - 4.0*det;

    if (discriminant < 0.0 && discriminant > -1e-12)
    {
        discriminant = 0.0;
    }

    if (discriminant < 0.0)
    {
        throw std::runtime_error("Negative discriminant in eigenvalue calculation.");
    }

    double eigenvalue_1 = (trace + std::sqrt(discriminant)) / 2.0;
    double eigenvalue_2 = (trace - std::sqrt(discriminant)) / 2.0;

    if (eigenvalue_1 < 0.0 && eigenvalue_1 > -1e-12) eigenvalue_1 = 0.0;
    if (eigenvalue_2 < 0.0 && eigenvalue_2 > -1e-12) eigenvalue_2 = 0.0;

    double lambda_1 = std::sqrt(eigenvalue_1);
    double lambda_2 = std::sqrt(eigenvalue_2);

    double energy_density =
        (mu / alpha) *
        (std::pow(lambda_1, alpha) + std::pow(lambda_2, alpha) - 2.0);

    return area0 * energy_density;
}