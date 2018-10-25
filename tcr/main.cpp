
#define LOG

#include "template.cpp"
#include "geometryessentials.cpp"
#include "prettyprinting.cpp"

#include "unionfind.cpp"
#include "linkedlist.cpp"
#include "trie.cpp"
#include "segmenttree.cpp"

#include "shoelace.cpp"
#include "intersections.cpp"
#include "convexhull.cpp"

#include "dijkstra.cpp"
#include "bellmanford.cpp"
#include "topologicalsort.cpp"
#include "stronglyconnectedcomponents.cpp"
#include "prim.cpp"

#include "stringmatching.cpp"
#include "longestincreasingsubsequence.cpp"

#include "primes.cpp"
#include "euclid.cpp"

int main(){
    cout << "-----o-----o----- DATA STRUCTURES -----o-----o-----" << endl << endl;
    testUnionFind();
    testLinkedList();
    testTrie();
    testSegmentTree();
    cout << "-----o-----o----- GEOMETRIC ALGORITHMS -----o-----o-----" << endl << endl;
    testShoelace();
    testIntersections();
    testConvexHull();
    cout << "-----o-----o----- GRAPH ALGORITHMS -----o-----o-----" << endl << endl;
    testDijkstra();
    testBellmanFord();
    testTopologicalSort();
    testStronglyConnectedComponents();
    testPrim();
    cout << "-----o-----o----- STRING AND LIST ALGORITHMS -----o-----o-----" << endl << endl;
    testStringMatching();
    testLongestIncreasingSubsequence();
    cout << "-----o-----o----- MATHEMATICAL ALGORITHMS -----o-----o-----" << endl << endl;
    testPrimes();
    testEuclid();
    return 0;
}
