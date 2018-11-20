
bool pointInPolygon(point p, vector<point> polygon){
    int n = polygon.size();
    bool b = false;
    for (int i = 0; i < n; i++){
        line l = {polygon[i], polygon[(i + 1) % n]};
        if (pointLine(p, l)) return true;
        if (l.p.y > l.q.y) swap(l.p, l.q);
        if (p.y > l.p.y && p.y <= l.q.y && ((p - l.p) ^ l.direction()) > 0) b ^= 1;
    }
    return b;
}
