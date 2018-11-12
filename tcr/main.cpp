
/*
TODO:

Simple:
Point in polygon
Distances / Closest point (point line segment DONE, line segment line segment, maybe something with circles)
Euler phi / totent
Johnson / Floyd-Warschall (All pairs shortest paths)

Complicated:
Order Statistics Tree (Balanced Binary Search Tree)
3D geometry intersections / distances / cross product / etc

Unfamiliar:
Suffix Tree (longest common substring)
(2D) Fenwick Tree
Linear system of equation solver (Matrix inverse)
Heavy Light Decomposition (Maximum Edge on Path query)
Least Common Ancestor in a Tree
Hierholzer (Euler path / cycle)
Min cost max flow
KD tree
Voronoi diagram
Hungarian algorithm
*/

#define LOG

#include "template/template.cpp"
#include "template/geometryessentials.cpp"
#include "template/prettyprinting.cpp"

#include "tests/datastructuretests.cpp"
#include "tests/geometricalgorithmtests.cpp"
#include "tests/graphtests.cpp"
#include "tests/stringssequencestests.cpp"
#include "tests/mathtests.cpp"

int main(){
    testDatastructures();
    testGeometricAlgorithms();
    testGraphs();
    testStringsSequences();
    testMaths();
    return 0;
}
