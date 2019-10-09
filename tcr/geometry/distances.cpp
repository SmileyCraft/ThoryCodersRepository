
template <typename N = ld>
N point_line_d2(point<N> p, line<N> l) {return square(l.dir() ^ (p - l.p)) / l.length_squared();}

template <typename N = ld>
N point_line_segment_d2(point<N> p, line<N> l){
    N x = point_line(p, l);
    if (x <= 0) return p.distance_squared(l.p);
    else if (x >= 1) return p.distance_squared(l.q);
    else return point_line_d2(p, l);
}

template <typename N = ld>
N line_segment_line_segment_d2(line<N> l1, line<N> l2){
    N x1 = line_line(l1, l2), x2 = line_line(l1, l2);
    if (x1 >= 0 && x1 <= 1 && x2 >= 0 && x2 <= 1) return 0;
    return min(min(point_line_segment_d2(l1.p, l2), point_line_segment_d2(l1.q, l2)),
            min(point_line_segment_d2(l2.p, l1), point_line_segment_d2(l2.q, l1)));
}
