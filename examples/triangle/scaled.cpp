#include <iostream>
#include "geometry/triangle.h"
int main()
{
    vec3 A{0.0, 0.0, 0.0};
    vec3 B{1.0, 0.0, 0.0};
    vec3 C{0.0, 1.0, 0.0};

    double area = triangle_area(A, B, C);
    double scaled_area = 2.0 * area;

    std::cout << "Original area: " << area << std::endl;
    std::cout << "Scaled area: " << scaled_area << std::endl;

    return 0;
}