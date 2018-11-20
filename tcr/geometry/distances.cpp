
NUMBER pointLineSegment(point p, line l){
    point d = l.q - l.p;
    point dm = l.p - p;
    NUMBER idm = d * dm;
    NUMBER idd = d * d;
    NUMBER inv = 1 / idd;

    NUMBER f = -idm * inv;
    point cp = l.p + f * d;
    if (f < 0) cp = l.p;
    if (f > 1) cp = l.q;

    return sqrt((cp - p).lengthSquared());
}

//THIS DOES NOT WORK WHEN THE LINE SEGMENTS STRICTLY INTERSECT
NUMBER lineSegmentLineSegment(line l1, line l2){
    return min(min(pointLineSegment(l1.p, l2), pointLineSegment(l1.q, l2)),
               min(pointLineSegment(l2.p, l1), pointLineSegment(l2.q, l1)));
}
