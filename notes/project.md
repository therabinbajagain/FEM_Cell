## Project Description
Ogden nonlinear deformation of a triangulated cell membrane, with each triangle acting as a membrane finite element

## Build 1: one triangle element object

For each triangulated cell membrane we need to compute:

-3 node indices
-its reference positions
-how to compute its reference area
-how to compute its current area
-how to compute its deformation measure

//Output

C++ writes triangle.vtk
ParaView opens triangle.vtk
You see one deformed triangle
C++ also prints reference area and current area

## Build 2
