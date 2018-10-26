
vector<point> convexhull(vector<point> points){ // O(n log n)
    // There must be at least two distinct points
    // Returns the convex hull polygon counterclockwise
    vector<point> hull;
    int l = 0;
    for (int i = 1; i < points.size(); i++)
        if (points[l].x == points[i].x ? points[l].y < points[i].y : points[l].x > points[i].x)
            l = i;
    hull.push_back(points[l]);
    for (int i = 0; i < points.size(); i++){
        if (points[i] == hull[0]){
            points[i] = points.back();
            points.pop_back();
            i--;
        }
    }
    sort(points.begin(), points.end(), [hull](point p, point q){
        p -= hull[0];
        q -= hull[0];
        return p.y * q.x == q.y * p.x ? (p.x == q.x ? p.y > q.y : p.x > q.x) : p.y * q.x < q.y * p.x;
    });
    points.push_back(hull[0]);
    for (int i = 0; i < points.size(); i++){
        while (true){
            if (hull.size() == 1){
                hull.push_back(points[i]);
                break;
            }
            line lastSegment = {hull[hull.size() - 2], hull[hull.size() - 1]};
            point relative = complexMultiply(points[i] - lastSegment.p, complexConjugate(lastSegment.direction()));
            if (relative.y == 0 && relative.x <= lastSegment.direction().lengthSquared()) break;
            if (relative.y <= 0) hull.pop_back();
            else{
                hull.push_back(points[i]);
                break;
            }
        }
    }
    hull.pop_back();
    return hull;
}