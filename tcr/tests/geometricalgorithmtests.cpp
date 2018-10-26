
#include "../geometry/shoelace.cpp"
#include "../geometry/intersections.cpp"
#include "../geometry/convexhull.cpp"
#include "../geometry/distances.cpp"

// SHOELACE

void testShoelace(){
    cout << "SHOELACE" << endl;
    vector<point> polygon = {{1,1},{2,1},{1,3}};
    cout << shoelace(polygon) << endl; // {(1.333 1.667) 1}
    polygon = {{0,0},{7,5},{1,4},{6,9},{-2,9},{3,8},{-2,3},{1,-3}};
    cout << shoelace(polygon) << endl; // {(1.774 4.369) 32.5}
    cout << endl;
}

// INTERSECTIONS

void testIntersections(){
    cout << "INTERSECTIONS" << endl;
    cout << lineLine({{0,0},{2,1}},{{2.0},{1,2}}) << endl; // (1.6 0.8)
    cout << lineCircle({{0,0},{2,1}},{{0,2},4}) << endl; // (1.6 0.8) (0 0)
    cout << circleCircle({{0,2},4},{{0,0},4}) << endl; // (-1.732 1) (1.732 1)
    cout << endl;
}

// CONVEX HULL

void testConvexHull(){
    cout << "CONVEX HULL" << endl;
    vector<point> points;
    for (int x = 0; x < 5; x++) for (int y = 0; y < 5; y++) points.push_back({x, y});
    cout << convexhull(points) << endl; // {(0 4) (0 0) (4 0) (4 4)}
    points.clear();
    for (int x = 0; x < 5; x++) for (int y = 4 - x; y < 5; y++) points.push_back({x, y});
    cout << convexhull(points) << endl; // {(0 4) (4 0) (4 4)}
    points.clear();
    for (int x = 0; x < 5; x++) for (int y = 0; y <= x; y++) points.push_back({x, y});
    cout << convexhull(points) << endl; // {(0 0) (4 0) (4 4)}
    points.clear();
    for (int x = 0; x < 5; x++) for (int y = vector<int>({1,2,2,1,0})[x]; y <= vector<int>({2,4,3,3,1})[x]; y++) points.push_back({x, y});
    cout << convexhull(points) << endl; // {(0 2) (0 1) (4 0) (4 1) (3 3) (1 4)}
    cout << endl;
}

// DISTANCES

void testDistances(){
    cout << "DISTANCES" << endl;
    cout << pointLineSegment({0,0},{{1,1},{2,3}}) << endl; // 1.414
    cout << pointLineSegment({0,0},{{1,0},{0,-1}}) << endl; // 0.707
    cout << pointLineSegment({0,0},{{1,1},{0,1}}) << endl; // 1
    cout << endl;
}

// COMBINED TEST

void testGeometricAlgorithms(){
    cout << "-----o-----o----- GEOMETRIC ALGORITHMS -----o-----o-----" << endl << endl;
    testShoelace();
    testIntersections();
    testConvexHull();
    testDistances();
}
