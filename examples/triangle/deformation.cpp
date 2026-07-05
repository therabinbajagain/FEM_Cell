#include <iostream>
#include "geometry/triangle.h"

int main()
{
    vec3 A{0.0, 0.0, 0.0};
    vec3 B{1.0, 0.4, 0.0};
    vec3 C{0.0, 1.0, 0.0};

    vec3 A0{0.0, 0.0, 0.0};
    vec3 B0{1.0, 0.0, 0.0};
    vec3 C0{0.0, 1.0, 0.0};

    double mu = 1.0;
    double alpha = 2.0;

    double W0 = ogden_triangle_energy(A, B, C, A0, B0, C0, mu, alpha);

    std::cout << "Ogden triangle energy: " << W0 << std::endl;

    double eps = 1e-6;

    vec3 A_perturbed = A;
    A_perturbed.x += eps;

    double W_plus = ogden_triangle_energy(
        A_perturbed, B, C,
        A0, B0, C0,
        mu, alpha
    );

    double force_Ax = -(W_plus - W0) / eps;

    std::cout << "Energy W0: " << W0 << std::endl;
    std::cout << "Energy W_plus: " << W_plus << std::endl;
    std::cout << "Force on A in x: " << force_Ax << std::endl;

    return 0;
}