
point INF_POINT = {-INF, 0};

struct parabola{
    NUMBER a, b, c;

    parabola operator-= (parabola p) {a -= p.a; b -= p.b; c -= p.c;}
    void operator*= (NUMBER r) {a *= r; b *= r; c *= r;}

    NUMBER solve(){
        if (a == 0) return -c / b;
        NUMBER d = b * b - 4 * a * c;
        if (d < 0) d = 0;
        return (-b - sqrt(d)) / (2 * a);
    }

    parabola(point p1, point p2, NUMBER x) : a(-1), b(2 * p1.y), c(x * x - p1.lengthSquared()) {*this *= x - p2.x;}
};

NUMBER parabolaIntersection(point p1, point p2, NUMBER x){
    if (p1.x == p2.x) return (p1.y + p2.y) / 2;
    parabola p(p1, p2, x);
    p -= parabola(p2, p1, x);
    return p.solve();
}

point circumCenter(point p1, point p2, point p3){
    point3 X = {p1.x, p2.x, p3.x}, Y = {p1.y, p2.y, p3.y}, U = {1, 1, 1},
           L = {p1.lengthSquared(), p2.lengthSquared(), p3.lengthSquared()};
    matrix3 MD = {U, X, Y}, MX = {U, X, L}, MY = {U, L, Y};
    point P = {MY.determinant(), MX.determinant()};
    return P / (2 * MD.determinant());
}

struct VoronoiEvent{
    NUMBER x;
    bool t; //true = add vertical line, false = report intersection
    int a, b, c;
    point m;
    bool operator> (const VoronoiEvent e) const {return x == e.x ? t && !e.t : x > e.x;}
};

struct VoronoiDiagram{
    int n;
    vector<point> dt, vd; //Delaunay triangulation vertices, Voronoi diagram vertices
    vector<unordered_map<int, int>> g; //Delaunay triangulation connections and right Voronoid vertex of corresponding dual edge

    void addTriangle(int a, int b, int c, point m){
        int j = vd.size();
        vd.push_back(m);
        g[a][b] = j;
        g[b][c] = j;
        g[c][a] = j;
    }

    void checkTriangle(int a, int b, int c, auto& q){
        if (a >= 0 && c >= 0 && ((dt[b] - dt[c]) ^ (dt[a] - dt[b])) > 0){
            point m = circumCenter(dt[a], dt[b], dt[c]);
            q.push({m.x + (m - dt[a]).length(), false, a, b, c, m});
        }
    }

    //set of points must be simple, O(n log n)
    VoronoiDiagram(vector<point> ps) : n(ps.size()), dt(ps), vd(0), g(n) {
        if (n == 0) return;
        ps.push_back(INF_POINT);

        unordered_map<NUMBER, vector<int>> cols;
        for (int i = 0; i < n; i++) cols[ps[i].x].push_back(i);
        priority_queue<VoronoiEvent, vector<VoronoiEvent>, greater<VoronoiEvent>> q;
        for (auto& p : cols){
            sort(p.second.begin(), p.second.end(), [&ps](int i, int j){return ps[i].y < ps[j].y;});
            q.push({p.first, true});
        }

        NUMBER x = q.top().x;
        q.pop();
        auto comp = [&](pair<int, int> p1, pair<int, int> p2){
            if (p1 == p2 || p1.second < 0 || p2.first < 0) return false;
            if (p1.first < 0 || p2.second < 0) return true;
            NUMBER y1 = parabolaIntersection(ps[p1.first], ps[p1.second], x), y2 = parabolaIntersection(ps[p2.first], ps[p2.second], x);
            if (y1 == y2){
                if (p1.first == n || p1.second == n || p2.first == n || p2.second == n) return false;
                return ps[p1.second].x == x;
            }
            return y1 < y2;
        };
        set<pair<int, int>, decltype(comp)> jumps(comp);

        vector<int> col = cols[x];
        jumps.insert({-1, col[0]});
        jumps.insert({col.back(), -1});
        for (int i = 0; i + 1 < col.size(); i++){
            jumps.insert({col[i], col[i + 1]});
            g[col[i]][col[i + 1]] = -1;
            g[col[i + 1]][col[i]] = -1;
        }

        while (!q.empty()){
            VoronoiEvent e = q.top();
            q.pop();
            if (e.t){
                x = e.x;
                for (int i : cols[x]){
                    auto it = jumps.lower_bound({i, n});
                    if (jumps.count({i, n})){
                        addTriangle(i, it->first, it->second, circumCenter(ps[i], ps[it->first], ps[it->second]));
                        jumps.erase(it);
                        it = jumps.lower_bound({i, n});
                    }
                    int c = it->first;
                    int d = it->second;
                    int a = (--it)->first;
                    int b = it->second;
                    g[b][i] = -1;
                    g[i][c] = -1;
                    checkTriangle(a, b, i, q);
                    checkTriangle(i, c, d, q);
                    jumps.insert({b, i});
                    jumps.insert({i, c});
                }
            }
            else if (jumps.count({e.a, e.b}) && jumps.count({e.b, e.c})){
                addTriangle(e.a, e.b, e.c, e.m);
                jumps.erase({e.a, e.b});
                jumps.erase({e.b, e.c});
                g[e.a][e.c] = -1;
                auto it = jumps.lower_bound({e.a, e.c});
                checkTriangle(e.a, e.c, it->second, q);
                checkTriangle((--it)->first, e.a, e.c, q);
                jumps.insert({e.a, e.c});
            }
        }
    }

    line dualLine(int a, int b){
        line dtl = {dt[a], dt[b]};
        point m = dtl.middle();
        point n = complexMultiply(dtl.direction(), {0, -1});
        n.normalize(INF);
        int c = g[a][b], d = g[b][a];
        return {c < 0 ? m + n : vd[c],
                d < 0 ? m - n : vd[d]};
    }
};
