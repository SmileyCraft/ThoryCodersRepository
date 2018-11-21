
#include "../graphs/dijkstra.cpp"
#include "../graphs/bellmanford.cpp"
#include "../graphs/topologicalsort.cpp"
#include "../graphs/stronglyconnectedcomponents.cpp"
#include "../graphs/prim.cpp"
#include "../graphs/hopcroftkarp.cpp"
#include "../graphs/dinic.cpp"

// SHORTEST PATHS

void testShortestPaths(){
    cout << "SHORTEST PATHS" << endl;
    vector<unordered_map<int, NUMBER>> graph = {{{0,2},{1,3},{2,5}},{{2,1},{3,2}},{{1,1},{3,5}},{{0,8},{1,1}},{}};
    cout << dijkstra(graph, 0) << endl; // {{0 0} {0 3} {1 4} {1 5} {-1 -1}}
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 3} {1 4} {1 5} {-1 -1}}
    graph[0][1] = 6;
    graph[1][2] = -2;
    cout << bellmanFord(graph, 0) << endl; // {}
    graph[2][1] = 2;
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 6} {1 4} {1 8} {-1 -1}}
    graph[0][4] = -10;
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 6} {1 4} {1 8} {0 -10}}
    cout << endl;
}

// TOPOLOGICAL SORT

void testTopologicalSort(){
    cout << "TOPOLOGICAL SORT" << endl;
    vector<vector<int>> graph = {{3},{0,4},{5,6},{},{0,8},{0,6},{0,3},{1,5},{}};
    cout << topologicalSort(graph) << endl; // {2 7 1 5 4 6 8 0 3}
    cout << endl;
}

// STRONGLY CONNECTED COMPONENTS

void testStronglyConnectedComponents(){
    cout << "STRONGLY CONNECTED COMPONENTS" << endl;
    vector<vector<int>> graph = {{1,4},{2,4},{3},{2,7},{5},{1,6},{2},{6}};
    cout << stronglyConnectedComponents(graph) << endl; // {{0} {1 5 4} {2 3 6 7}}
    graph = {{3,5,6},{2},{1,3},{0,2,4},{3},{0,8},{7},{8},{6,10},{8},{9},{4,14,15},{4,11,13},{14},
            {12,13,17},{17},{8,15},{19},{10,16},{18},{13,22},{20},{13,20,21}};
    cout << stronglyConnectedComponents(graph) << endl; // {{20 21 22} {11 12 14 13} {17 15 16 18 19} {0 3 5 2 4 1} {8 7 9 6 10}}
    cout << endl;
}

// PRIM

void addUndirectedEdge(vector<unordered_map<int, NUMBER>>& graph, int a, int b, NUMBER length){
    graph[a][b] = length;
    graph[b][a] = length;
}

void testPrim(){
    cout << "PRIM" << endl;
    vector<unordered_map<int, NUMBER>> graph(6);
    addUndirectedEdge(graph, 0, 1, 1);
    addUndirectedEdge(graph, 0, 3, 4);
    addUndirectedEdge(graph, 0, 4, 3);
    addUndirectedEdge(graph, 1, 3, 4);
    addUndirectedEdge(graph, 1, 4, 2);
    addUndirectedEdge(graph, 2, 4, 4);
    addUndirectedEdge(graph, 2, 5, 5);
    addUndirectedEdge(graph, 3, 4, 4);
    addUndirectedEdge(graph, 4, 5, 7);
    cout << prim(graph) << endl; // {{0 1} {1 4} {1 3} {4 2} {2 5}}
    cout << endl;
}

// HOPCROFT KARP

void testHopcroftKarp(){
    cout << "HOPCROFT KARP" << endl;
    vector<vector<int>> graph = {{0,1},{0,4},{2,3},{0,4},{1,3}};
    cout << hopcroftKarp(graph) << endl; // {1 4 2 0 3}
    cout << endl;
}

// DINIC

void testDinic(){
    cout << "DINIC" << endl;
    vector<unordered_map<int, NUMBER>> graph = {{{1,10},{2,10}},{{2,2},{3,4},{4,8}},{{4,9}},{{5,10}},{{3,6},{5,10}},{}};
    cout << dinic(graph, 0, 5) << endl;
    // {{{2 9} {1 10}} {{0 -10} {4 6} {2 0} {3 4}} {{1 0} {0 -9} {4 9}} {{4 -5} {1 -4} {5 9}} {{2 -9} {1 -6} {5 10} {3 5}} {{4 -10} {3 -9}}}
    cout << minCut(graph, 0, 5) << endl; // {{0 1} {2 4}}
    cout << endl;
}

// COMBINED TEST

void testGraphs(){
    cout << "-----o-----o----- GRAPH ALGORITHMS -----o-----o-----" << endl << endl;
    testShortestPaths();
    testTopologicalSort();
    testStronglyConnectedComponents();
    testPrim();
    testHopcroftKarp();
    testDinic();
}
