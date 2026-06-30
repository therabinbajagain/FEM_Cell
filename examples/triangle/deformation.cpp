#include <iostream>
#include "geometry/triangle.h"
#include <cmath>

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

    // std::cout << "Original area: " << area0 << std::endl;
    // std::cout << "Deformed area: " << area << std::endl;
    // std::cout << "Area ratio: " << ratio << std::endl;

    vec3 E1 = subtract(B0,A0);
    vec3 E2 = subtract(C0,A0);
    vec3 e1 = subtract(B,A);
    vec3 e2 = subtract(C,A);
    // std::cout << "E1: (" << E1.x << ", " << E1.y << ", " << E1.z << ")" << std::endl;
    // std::cout << "E2: (" << E2.x << ", " << E2.y << ", " << E2.z << ")" << std::endl;   
    // std::cout << "e1: (" << e1.x << ", " << e1.y << ", " << e1.z << ")" << std::endl;
    // std::cout << "e2: (" << e2.x << ", " << e2.y << ", " << e2.z << ")" << std::endl;  

    double stretch1 = norm(e1)/norm(E1);
    double stretch2 = norm(e2)/norm(E2);
    // std::cout << "Stretch along e1: " << stretch1 << std::endl;
    // std::cout << "Stretch along e2: " << stretch2 << std::endl;

    vec2 c1{e1.x, e1.y};
    vec2 c2{e2.x, e2.y};
    mat2 Dm = make_columns(c1, c2);

    vec2 C1{E1.x, E1.y};
    vec2 C2{E2.x, E2.y};
    mat2 Ds = make_columns(C1, C2); 

    std::cout << "Deformation gradient F: " << std::endl;
    std::cout << Dm.m00 << " " << Dm.m01 << std::endl;
    std::cout << Dm.m10 << " " << Dm.m11 << std::endl;
    
    mat2 F = matmul(Dm, transpose(Ds));
    
    mat2 C_tensor = matmul(transpose(F), F);

    std::cout << "Cauchy-Green deformation tensor C: " << std::endl;
    std::cout << C_tensor.m00 << " " << C_tensor.m01 << std::endl;
    std::cout << C_tensor.m10 << " " << C_tensor.m11 << std::endl;    

    double trace = C_tensor.m00 + C_tensor.m11;
    double det = C_tensor.m00 * C_tensor.m11 - C_tensor.m01 * C_tensor.m10;

    double eigenvalue_1 = trace/2 + std::sqrt((trace/2)*(trace/2) - det);
    double eigenvalue_2 = trace/2 - std::sqrt((trace/2)*(trace/2) - det);

    double lambda_1 = sqrt(eigenvalue_1);
    double lambda_2 = sqrt(eigenvalue_2);

    std::cout << "Principal stretch 1: " << lambda_1 << std::endl;
    std::cout << "Principal stretch 2: " << lambda_2 << std::endl;

    return 0;
}   