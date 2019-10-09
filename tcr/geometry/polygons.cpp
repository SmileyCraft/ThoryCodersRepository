
// Return area and center of gravity of polygon in O(n) time.
template <typename N = ld>
pair<N, point<N>> shoelace(const vector<point<N>> &poly){
    ll n = poly.size();
    N area = 0; point<N> center;
    for (ll i = 0; i < n; ++i){
        line<N> l = {poly[i], poly[(i + 1) % n]};
        N t = l.p ^ l.q;
        area += t; center += (l.p + l.q) * t;
    }
    return {area / 2, center / (3 * area)};
}

// Determines whether a point lies non-strictly inside a polygon in O(n) time.
template <typename N = ld>
bool point_in_polygon(point<N> p, const vector<point<N>> &poly){
    ll n = poly.size();
    bool retval = false;
    for (ll i = 0; i < n; ++i){
        line<N> l = {poly[i], poly[(i + 1) % n]};
        if (point_line_segment_d2(p, l) == 0) return true;
        if (l.p.y > l.q.y) swap(l.p, l.q);
        if (l.p.y <= p.y && p.y < l.q.y && (l.dir() ^ (p - l.p)) > 0) retval = !retval;
    }
    return retval;
}
