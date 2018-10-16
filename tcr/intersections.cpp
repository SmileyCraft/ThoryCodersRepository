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

point operator* (double d, point p){
    return point(d * p.x, d * p.y);
}

void testIntersections(){
    point p = point(1, 1);
    point q = point(2, 3);
    cout << ((p ^ q) * (q + p)).toString() << endl;
}
