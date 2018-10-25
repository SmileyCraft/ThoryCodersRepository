
long double pointLineSegment(point p, line l){
    point d = l.q - l.p;
    point dm = l.p - p;
    long double idm = d * dm;
    long double idd = d * d;
    long double inv = 1 / idd;

    long double f = -idm * inv;
    if (f < 0) return sqrt((l.p - p).lengthSquared());
    if (f > 1) return sqrt((l.q - p).lengthSquared());
    return sqrt((l.p + f * d - p).lengthSquared());
}
