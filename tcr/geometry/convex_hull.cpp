
// Find the convex hull of a non-empty set of points in O(n*log(n)) time.
// The result is strictly convex and counterclockwise, starting with the lexicographically smallest point.
template <typename N = ld>
vll convex_hull(const vector<point<N>> &ps){
    ll n = ps.size();
    vll hull = {0}, todo;
    for (ll i = 1; i < n; ++i) if (ps[i].y == ps[hull[0]].y ? ps[i].x < ps[hull[0]].x : ps[i].y < ps[hull[0]].y) hull[0] = i;
    for (ll i = 0; i < n; ++i) if (ps[i] != ps[hull[0]]) todo.push_back(i);
    sort(todo.begin(), todo.end(), [&](ll i, ll j){
        point<N> p1 = ps[i] - ps[hull[0]], p2 = ps[j] - ps[hull[0]];
        return (p1 ^ p2) == 0 ? p1.length_squared() < p2.length_squared() : (p1 ^ p2) > 0;
    });
    for (ll i : todo){
        hull.push_back(i);
        while (hull.size() >= 3){
            ll m = hull.size();
            point<N> p1 = ps[hull[m - 3]], p2 = ps[hull[m - 2]], p3 = ps[hull[m - 1]];
            line<N> l1 = {p1, p2}, l2 = {p2, p3};
            if ((l1.dir() ^ l2.dir()) > 0) break;
            hull.erase(hull.end() - 2);
        }
    }
    return hull;
}
