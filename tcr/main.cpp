
/*
TODO:

Simple:
Distances / Closest point (point line segment, line segment line segment, maybe something with circles)
Euler phi / totent
Johnson / Floyd-Warschall (All pairs shortest paths)

Complicated:
Dinic (max flow, maybe a separate min cut method)
Order Statistics Tree (Balanced Binary Search Tree)
3D geometry intersections / distances / cross product / etc

Unfamiliar:
Suffix Tree (longest common substring)
(2D) Fenwick Tree
Linear system of equation solver (Matrix inverse)
Heavy Light Decomposition (Maximum Edge on Path query)
Least Common Ancester in a Tree
Hierholzer
Bron-Kerbosch
Min cost max flow
KD tree
Voranoid diagram
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
