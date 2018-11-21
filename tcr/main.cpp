
/*
TODO:

Johnson / Floyd-Warschall (All pairs shortest paths)
Suffix Tree (longest common substring)
(2D) Fenwick Tree
Hierholzer (Euler path / cycle)
Min cost max flow
KD tree
Hungarian algorithm
Simplex algorithm
*/

#define LOG

#include "template/template.cpp"
#include "template/misc.cpp"
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
