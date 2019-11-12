
// Return x such that p projects onto l(x).
template <typename N = ld>
N point_line(point<N> p, line<N> l) {return (l.dir() * (p - l.p)) / l.length_squared();}

// Determines whether p is on l.
template <typename N = ld>
bool point_line_segment(point<N> p, line<N> l) {return ((l.p - p) ^ (l.q - p)) == 0 && (l.p - p) * (l.q - p) <= 0;}

// Return x such that l1(x) lies on l2.
template <typename N = ld>
N line_line(line<N> l1, line<N> l2) {return -(l2.dir() ^ (l1.p - l2.p)) / (l2.dir() ^ l1.dir());}

// Return x_1 < x_2 such that both l(x_i) lie on c.
template <typename N = ld>
pair<N, N> line_circle(line<N> l, circle<N> c){
    N x = point_line(c.p, l);
    N s = sqrtl(c.r2 - c.p.distance_squared(l(x))) / l.length();
    return {x - s, x + s};
}

// Return both intersections, the first one to the right of the line {c1,c2} and the second one to the left.
template <typename N = ld>
pair<point<N>, point<N>> circle_circle(circle<N> c1, circle<N> c2){
    point<N> d = c2.p - c1.p;
    point<N> n = {d.y, -d.x};
    N inv = 1 / d.length_squared();
    N f = (1 + (c1.r2 - c2.r2) * inv) / 2;
    N s = sqrtl(c1.r2 * inv - f * f);
    return {c1.p + f * d + s * n, c1.p + f * d - s * n};
}
