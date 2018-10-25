
#define LOG

#include "template/template.cpp"
#include "template/geometryessentials.cpp"
#include "template/prettyprinting.cpp"

#include "datastructures/unionfind.cpp"
#include "datastructures/linkedlist.cpp"
#include "datastructures/trie.cpp"
#include "datastructures/segmenttree.cpp"

#include "geometry/shoelace.cpp"
#include "geometry/intersections.cpp"
#include "geometry/convexhull.cpp"

#include "graphs/dijkstra.cpp"
#include "graphs/bellmanford.cpp"
#include "graphs/topologicalsort.cpp"
#include "graphs/stronglyconnectedcomponents.cpp"
#include "graphs/prim.cpp"

#include "stringssequences/stringmatching.cpp"
#include "stringssequences/longestincreasingsubsequence.cpp"

#include "maths/primes.cpp"
#include "maths/euclid.cpp"

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
