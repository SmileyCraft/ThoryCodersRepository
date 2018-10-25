
point lineLine(line l1, line l2){ // O(1)
    point d1 = l1.q - l1.p;
    point d2 = l2.q - l2.p;
    point dp = l2.p - l1.p;

    // Lines must not be parallel, so d1 ^ d2 != 0
    // Segments intersect iff 0 <= f1,f2 <= 1

    NUMBER s1 = dp.x * d2.y - dp.y * d2.x;
    // NUMBER s2 = dp.x * d1.y - dp.y * d1.x;
    NUMBER inv = 1 / (d1 ^ d2);
    NUMBER f1 = s1 * inv;
    // NUMBER f2 = s2 * inv;

    return l1.p + f1 * d1;
}

pair<point, point> lineCircle(line l, circle c){ // O(1)
    point dl = l.q - l.p;
    point dm = c.m - l.p;

    NUMBER imm = dm * dm;
    NUMBER ilm = dl * dm;
    NUMBER ill = dl * dl;

    // Line must not be degenerate, so l.p != l.q
    // Line and circle intersect iff disc >= 0
    // Line segment intersects iff 0 <= fi <= 1

    NUMBER disc = ilm * ilm + ill * (c.r2 - imm);
    NUMBER s = sqrt(disc);
    NUMBER inv = 1 / ill;
    NUMBER f1 = (ilm + s) * inv;
    NUMBER f2 = (ilm - s) * inv;

    return pair<point, point>(l.p + f1 * dl, l.p + f2 * dl);
}

pair<point, point> circleCircle(circle c1, circle c2){ // O(1)
    point d = c2.m - c1.m;
    point n = {d.y, -d.x};

    // Circles must not have the same center
    // Circles intersect iff disc >= 0

    NUMBER inv = 1 / (d * d);
    NUMBER f = (1 + (c1.r2 - c2.r2) * inv) / 2;
    NUMBER disc = c1.r2 * inv - f * f;
    NUMBER s = sqrt(disc);

    return pair<point, point>(c1.m + f * d + s * n, c1.m + f * d - s * n);
}

// TESTING

void testIntersections(){
    cout << "INTERSECTIONS" << endl;
    cout << lineLine({{0,0},{2,1}},{{2.0},{1,2}}) << endl; // (1.6 0.8)
    cout << lineCircle({{0,0},{2,1}},{{0,2},4}) << endl; // (1.6 0.8) (0 0)
    cout << circleCircle({{0,2},4},{{0,0},4}) << endl; // (-1.732 1) (1.732 1)
    cout << endl;
}
