
struct point {
    NUMBER x, y;

    bool operator== (point p) {return x == p.x && y == p.y;}
    point operator- (point p) {return {x - p.x, y - p.y};}
    void operator-= (point p) {x -= p.x; y -= p.y;}
    point operator+ (point p) {return {x + p.x, y + p.y};}
    void operator+= (point p) {x += p.x; y += p.y;}
    point operator/ (NUMBER r) {return {x / r, y / r};}
    void operator/= (NUMBER r) {x /= r; y /= r;}
    NUMBER operator* (point p) {return x * p.x + y * p.y;}
    NUMBER operator^ (point p) {return x * p.y - y * p.x;}

    NUMBER lengthSquared() {return x * x + y * y;}
    NUMBER length() {return sqrt(lengthSquared());}
};

point operator* (NUMBER d, point p) {return {d * p.x, d * p.y};}

point complexConjugate(point p) {return {p.x, -p.y};}
point complexMultiply(point p, point q) {return {p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x};}

struct line{
    point p, q;

    point direction() {return q - p;}
    NUMBER lengthSquared() {return direction().lengthSquared();}
    NUMBER length() {return direction().length();}
};

struct circle{
    point m;
    NUMBER r2;
};
