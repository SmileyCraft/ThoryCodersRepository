
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
