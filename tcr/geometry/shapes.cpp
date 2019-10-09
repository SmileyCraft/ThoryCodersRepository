
template <typename N = ld>
struct point{
    N x, y;

    point(N x_ = 0, N y_ = 0) : x(x_), y(y_) {}

    N operator* (point<N> p) {return x * p.x + y * p.y;} // inner product
    N operator^ (point<N> p) {return x * p.y - y * p.x;} // cross product
    
    N length_squared() {return x * x + y * y;}
    N distance_squared(point<N> p) {return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);}
    N length() {return sqrtl(length_squared());}
    N distance(point<N> p) {return sqrtl(distance_squared(p));}
    P &normalize() {return *this /= length();}
};

template <typename N = ld>
struct line{
    point<N> p, q;

    line(point<N> p_ = {0, 0}, point<N> q_ = {0, 0}) : p(p_), q(q_) {}

    point<N> dir() {return q - p;}
    N length() {return p.distance(q);}
    N length_squared() {return p.distance_squared(q);}

    point<N> operator() (N n) {return p + n * dir();}
};

template <typename N = ld>
struct circle{
    point<N> p; N r2; // r2 = radius squared

    circle(point<N> p_ = {0, 0}, N r2_ = 1) : p(p_), r2(r2_) {}

    N r() {return sqrtl(r2);}
    N area() {return CONST_PI * r2;}
    N circumference() {return 2 * CONST_PI * r();}
};
