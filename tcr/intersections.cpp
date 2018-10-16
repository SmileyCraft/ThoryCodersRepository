struct point {
    double x, y;

    point(double x, double y) : x(x), y(y) {}

    point operator- (point p){
        return point(x - p.x, y - p.y);
    }

    point operator+ (point p){
        return point(x + p.x, y + p.y);
    }

    double operator* (point p){
        return x * p.x + y * p.y;
    }

    double operator^ (point p){
        return x * p.y - y * p.x;
    }

    string toString(){
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

struct line{
    point p, q;
    line(point p, point q) : p(p), q(q) {}
};

struct circle{
    point m;
    double r2;
    circle(point m, double r2) : m(m), r2(r2) {}
};

point operator* (double d, point p){
    return point(d * p.x, d * p.y);
}

point lineLine(line l1, line l2){
    point d1 = l1.q - l1.p;
    point d2 = l2.q - l2.p;
    point d = l2.p - l1.p;

    //Lines intersect if n != 0
    //Segments intersect iff 0 <= f1,f2 <= 1

    double t1 = d.x * d2.y - d.y * d1.x;
    //double t2 = d.x * d1.y - d.y * d2.x;
    double n = d1 ^ d2;
    double f1 = t1 / n;
    //double f2 = t2 / n;

    return l1.p + f1 * d1;
}

pair<point, point> lineCircle(line l, circle c){
    point d = l.q - l.p;
    point dm = l.p - c.m;

    double imm = dm * dm;
    double idm = d * dm;
    double idd = d * d;

    //Line and circle intersect iff disc >= 0
    //Line segment intersects iff 0 <= fi <= 1

    double disc = idm * idm + idd * (c.r2 - imm);
    double w = sqrt(disc);
    double inv = 1 / idd;
    double f1 = (-idm + w) * inv;
    double f2 = (-idm - w) * inv;

    return pair<point, point>(l.p + f1 * d, l.p + f2 * d);
}

pair<point, point> circleCircle(circle c1, circle c2){
    point m = c2.m - c1.m;
    point n = point(m.y, -m.x);

    double f = 1 / (m * m);
    double c = (1 - (c2.r2 - c1.r2) * f) * 0.5;
    double a = sqrt(c1.r2 * f - c * c);

    return pair<point, point>(c1.m + c * m + a * n, c1.m + c * m - a * n);
}

void testIntersections(){
    point p1 = point(0, 0);
    point q1 = point(2, 1);
    line l1 = line(p1, q1);
    point p2 = point(2, 0);
    point q2 = point(1, 2);
    line l2 = line(p2, q2);
    circle c1 = circle(point(0,2), 4);
    circle c2 = circle(point(0,0), 4);
    cout << lineLine(l1, l2).toString() << endl; //(1.6,0.8)
    cout << lineCircle(l1, c1).first.toString() << ' ' << lineCircle(l1, c1).second.toString() << endl; //(1.6,0.8) (0,0)
    cout << circleCircle(c1, c2).first.toString() << ' ' << circleCircle(c1, c2).second.toString() << endl; //(-sq3, 1) (sq3, 1)
}
