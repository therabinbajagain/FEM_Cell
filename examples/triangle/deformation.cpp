#include <iostream>
#include "geometry/triangle.h"

int main(){
    vec3 A{0.0, 0.0, 0.0};
    vec3 B{1.0, 0.0, 0.0};
    vec3 C{0.0, 1.2, 0.0};

    vec3 A0{0.0, 0.0, 0.0};
    vec3 B0{1.0, 0.0, 0.0};
    vec3 C0{0.0, 1.0, 0.0};

    double area = triangle_area(A,B,C);
    double area0 = triangle_area(A0,B0,C0);
    double ratio = area/area0;

    std::cout << "Original area: " << area0 << std::endl;
    std::cout << "Deformed area: " << area << std::endl;
    std::cout << "Area ratio: " << ratio << std::endl;

    vec3 E1 = subtract(B0,A0);
    vec3 E2 = subtract(C0,A0);
    vec3 e1 = subtract(B,A);
    vec3 e2 = subtract(C,A);
    std::cout << "E1: (" << E1.x << ", " << E1.y << ", " << E1.z << ")" << std::endl;
    std::cout << "E2: (" << E2.x << ", " << E2.y << ", " << E2.z << ")" << std::endl;   
    std::cout << "e1: (" << e1.x << ", " << e1.y << ", " << e1.z << ")" << std::endl;
    std::cout << "e2: (" << e2.x << ", " << e2.y << ", " << e2.z << ")" << std::endl;  

    double stretch1 = norm(e1)/norm(E1);
    double stretch2 = norm(e2)/norm(E2);
    std::cout << "Stretch along e1: " << stretch1 << std::endl;
    std::cout << "Stretch along e2: " << stretch2 << std::endl;

    return 0;
}