
NUMBER pointLineSegment(point p, line l){
    point d = l.q - l.p;
    point dm = l.p - p;
    NUMBER idm = d * dm;
    NUMBER idd = d * d;
    NUMBER inv = 1 / idd;

    NUMBER f = -idm * inv;
    if (f < 0) return sqrt((l.p - p).lengthSquared());
    if (f > 1) return sqrt((l.q - p).lengthSquared());
    return sqrt((l.p + f * d - p).lengthSquared());
}
