
#include "../geometry/shoelace.cpp"
#include "../geometry/intersections.cpp"
#include "../geometry/convexhull.cpp"
#include "../geometry/distances.cpp"
#include "../geometry/pointinpolygon.cpp"
#include "../geometry/sortlinesegments.cpp"
#include "../geometry/voronoi.cpp"

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
    cout << pointLine({2,1},{{0,0},{4,2}}) << " "; // 1
    cout << pointLine({2,1},{{0,0},{2,1}}) << " "; // 1
    cout << pointLine({4,2},{{0,0},{2,1}}) << " "; // 0
    cout << pointLine({2,1},{{0,0},{5,2}}) << endl; // 0
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
    cout << lineSegmentLineSegment({{0,0},{1,0}},{{2,1},{2,2}}) << endl; // 1.41421
    cout << lineSegmentLineSegment({{0,0},{4,1}},{{1,2},{2,2}}) << endl; // 1.45521
    cout << endl;
}

// POINT IN POLYGON

void testPointInPolygon(){
    cout << "POINT IN POLYGON" << endl;
    cout << pointInPolygon({1,2},{{1,0},{2,3},{1,1},{0,3}}) << " "; // 0
    cout << pointInPolygon({1,2},{{0,0},{2,0},{1,2}}) << " "; // 1
    cout << pointInPolygon({0,2},{{0,0},{2,0},{1,2}}) << " "; // 0
    cout << pointInPolygon({0,0},{{0,2},{1,0},{2,2}}) << " "; // 0
    cout << pointInPolygon({1,1},{{0,2},{0,0},{2,1},{3,1}}) << endl; // 1
    cout << endl;
}

// SORT LINE SEGMENTS

void testSortLineSegments(){
    cout << "SORT LINE SEGMENTS" << endl;
    cout << sortLineSegments({{{0,1},{1,1}},{{2,1},{3,1}},{{0,0},{3,0}},{{0,2},{3,2}}}) << endl; // {2 0 1 3}
    cout << endl;
}

// VORONOI DIAGRAM

template <class T>
basic_ostream<T>& operator<< (basic_ostream<T>& str, VoronoiDiagram vd) {
    str << vd.vd;
    return str;
}

void testVoronoi(){
    cout << "VORONOI DIAGRAM" << endl;
    cout << VoronoiDiagram({{-1.5,3.2},{1.8,3.3},{-3.7,1.5},{-1.5,1.3},{0.8,1.2},{3.3,1.5},{-4.0,-1.0},
        {-2.3,-0.7},{0.0,-0.5},{2.0,-1.5},{3.7,-0.8},{-3.5,-2.9},{-0.9,-3.9},{2.0,-3.5},{3.5,-2.25}}) << endl;
        // {(-3.33317 0.187981) (-2.99112 -1.7503) (-2.67193 0.608772) (-2.52273 2.25) (-1.81272 -2.39306) (-1.20405 0.0216216)
        // (-1.02408 -2.04804) (-0.373308 0.71391) (-0.306522 2.25) (0.163909 2.791) (0.300649 -2.3987) (0.384483 -2.5)
        // (1.43214 -0.135714) (1.98091 1.92576) (2.4375 -2.5) (2.18797 0.200211) (2.96855 -1.4379) (2.31706 0.144272)}
    cout << VoronoiDiagram({{0,0},{1,0},{0,1},{1,1}}) << endl; // {(0.5 0.5) (0.5 0.5)}
    cout << VoronoiDiagram({{0,1},{0,0},{1,0},{1,1}}) << endl; // {(0.5 0.5) (0.5 0.5)}
    cout << VoronoiDiagram({{1,0},{0,1},{-1,0},{0,-1}}) << endl; // {(-0 -0) (-0 -0)}
    cout << VoronoiDiagram({{10,0},{0,11},{-10,0},{0,-11}}) << endl; // {(-0 0.954545) (-0 -0.954545)}
    cout << VoronoiDiagram({{0,0},{2,1},{4,2}}) << endl; // {}
    cout << VoronoiDiagram({{0,0},{2,1},{1,2}}) << endl; // {(0.833333 0.833333)}
    cout << VoronoiDiagram({{5,0},{4,3},{3,4},{0,5},{-3,4},{-4,3},{-5,0},{-4,-3},{-3,-4},{0,-5},{3,-4},{4,-3}}) << endl;
        // {(-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0) (-0 -0)}
    cout << VoronoiDiagram({{0,0},{1,0},{2,0},{0,1},{1,1},{2,1},{0,2},{1,2},{2,2}}) << endl;
        // {(0.5 0.5) (0.5 1.5) (0.5 0.5) (0.5 1.5) (1.5 0.5) (1.5 1.5) (1.5 0.5) (1.5 1.5)}
    cout << endl;
}

// COMBINED TEST

void testGeometricAlgorithms(){
    cout << "-----o-----o----- GEOMETRIC ALGORITHMS -----o-----o-----" << endl << endl;
    testShoelace();
    testIntersections();
    testConvexHull();
    testDistances();
    testPointInPolygon();
    testSortLineSegments();
    testVoronoi();
}
