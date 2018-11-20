
struct point {
    NUMBER x, y;

    bool operator== (point p) {return x == p.x && y == p.y;}
    point operator- (point p) {return {x - p.x, y - p.y};}
    void operator-= (point p) {x -= p.x; y -= p.y;}
    point operator+ (point p) {return {x + p.x, y + p.y};}
    void operator+= (point p) {x += p.x; y += p.y;}
    point operator/ (NUMBER r) {return {x / r, y / r};}
    void operator/= (NUMBER r) {x /= r; y /= r;}
    point operator* (NUMBER r) {return {x * r, y * r};}
    void operator*= (NUMBER r) {x *= r; y *= r;}
    NUMBER operator* (point p) {return x * p.x + y * p.y;}
    NUMBER operator^ (point p) {return x * p.y - y * p.x;}

    NUMBER lengthSquared() {return x * x + y * y;}
    NUMBER length() {return sqrt(lengthSquared());}
    void normalize(NUMBER x) {*this *= (x / length());}
};

point operator* (NUMBER d, point p) {return {d * p.x, d * p.y};}

point complexConjugate(point p) {return {p.x, -p.y};}
point complexMultiply(point p, point q) {return {p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x};}

struct point3{
    NUMBER x, y, z;

    NUMBER operator* (point3 p) {return x * p.x + y * p.y + z * p.z;}
    point3 operator^ (point3 p) {return {y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x};}
};

struct matrix3{
    point3 c1, c2, c3;

    NUMBER determinant() {return c1 * (c2 ^ c3);}
};

struct line{
    point p, q;

    point direction() {return q - p;}
    point middle() {return (p + q) / 2;}
    NUMBER lengthSquared() {return direction().lengthSquared();}
    NUMBER length() {return direction().length();}
};

struct circle{
    point m;
    NUMBER r2;
};

template <class T>
basic_ostream<T>& operator<< (basic_ostream<T>& str, point p) {return str << "(" << p.x << " " << p.y << ")";}
template <class T>
basic_ostream<T>& operator<< (basic_ostream<T>& str, line l) {return str << "(" << l.p << " " << l.q << ")";}
template <class T>
basic_ostream<T>& operator<< (basic_ostream<T>& str, circle c) {return str << "(" << c.m << " " << c.r2 << ")";}
