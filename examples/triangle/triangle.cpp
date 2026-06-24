#include <iostream>
#include <cmath>
using namespace std;

// defining a vector struct to represent points and vectors in 3D space
struct vec3
{
    double x, y, z;
};

// function to subtract two vectors
vec3 subtract(vec3 a, vec3 b)
{
    return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}

// function to compute the cross product of two vectors
vec3 cross(vec3 a, vec3 b)
{
    return vec3{a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x};
}

// function to compute the magnitude of a vector
double magnitude(vec3 v)
{    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}   

int main()
{
    vec3 A{0.0,0.0,0.0};
    vec3 B{1.0, 0.0, 0.0};
    vec3 C{0.0, 1.0, 0.0};

    // get point coordinates
    cout << "Point A: "<<A.x <<","<<A.y << ","<<A.z <<endl;
    cout << "Point B: "<<B.x <<","<<B.y << ","<<B.z <<endl;
    cout << "Point C: "<<C.x <<","<<C.y << ","<<C.z <<endl;

    // get edge vectors
    vec3 e1 = subtract(B, A);
    vec3 e2 = subtract(C, A);
    cout << "Edge 1: "<<e1.x <<","<<e1.y << ","<<e1.z <<endl;
    cout << "Edge 2: "<<e2.x <<","<<e2.y << ","<<e2.z <<endl;
    
    // compute normal vector using cross product
    vec3 normal = cross(e1, e2);
    cout << "Normal vector: "<<normal.x <<","<<normal.y << ","<<normal.z <<endl;    

    // compute area of triangle using magnitude of normal vector
    double area = 0.5 * magnitude(normal);
    cout << "Area of triangle: "<<area <<endl;  
}
