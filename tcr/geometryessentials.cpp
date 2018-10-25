
struct point {
    NUMBER x, y;

    point(NUMBER x = 0, NUMBER y = 0) : x(x), y(y) {}

    bool operator== (point p) {return x == p.x && y == p.y;}
    point operator- (point p) {return point(x - p.x, y - p.y);}
    void operator-= (point p) {x -= p.x; y -= p.y;}
    point operator+ (point p) {return point(x + p.x, y + p.y);}
    void operator+= (point p) {x += p.x; y += p.y;}
    point operator/ (NUMBER r) {return point(x / r, y / r);}
    void operator/= (NUMBER r) {x /= r; y /= r;}
    NUMBER operator* (point p) {return x * p.x + y * p.y;}
    NUMBER operator^ (point p) {return x * p.y - y * p.x;}

    NUMBER lengthSquared() {return x * x + y * y;}
    NUMBER length() {return sqrt(lengthSquared());}
};

point operator* (NUMBER d, point p) {return point(d * p.x, d * p.y);}

point complexConjugate(point p) {return point(p.x, -p.y);}
point complexMultiply(point p, point q) {return point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}

struct line{
    point p, q;

    line(point p, point q) : p(p), q(q) {}

    point direction() {return q - p;}
    NUMBER lengthSquared() {return direction().lengthSquared();}
    NUMBER length() {return direction().length();}
};

struct circle{
    point m;
    NUMBER r2;

    circle(point m, NUMBER r2) : m(m), r2(r2) {}
};
