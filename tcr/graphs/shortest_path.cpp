
// Find the minimum weight path to all nodes from a single source in a directed non-negative weighted graph in O(m*log(m)) time.
// At position t in the output we have {i, j, w} where g[i][j] is the last edge on path from s to t of minimum weight w.
// We have w=-1 if no such path exists and i=j=-1 if no last edge exists.
template <typename N = ll>
vector<weighted_edge<N>> dijkstra(const weighted_graph<N> &g, ll s){
    vector<weighted_edge<N>> r(g.size());
    priority_queue<weighted_edge<N>, vector<weighted_edge<N>>, greater<weighted_edge<N>>> q;
    q.push({-1, -1, 0});
    while (!q.empty()){
        weighted_edge<N> e = q.top();
        q.pop();
        ll t = e.i == -1 ? s : g[e.i][e.j].first;
        if (r[t].w != -1) continue;
        r[t] = e;
        for (ll i = 0; i < g[t].size(); ++i) q.push({t, i, e.w + g[t][i].second});
    }
    return r;
}

// Find the minimum weight path to all nodes from a single source in a directed weighted graph in O(n*m) time.
// The graph may have negative edges and negative cycles.
// At position t in the output we have {i, j, w} where g[i][j] is the last edge on path from s to t of minimum weight w.
// We have w=INF if no such path exists, w=-INF if the path can have arbitrarily small weight and i=j=-1 if no last edge exists.
template <typename N = ll>
vector<weighted_edge<N>> bellman_ford(const weighted_graph<N> &g, ll s){
    vector<weighted_edge<N>> r(g.size(), {-1, -1, INF});
    r[s].w = 0;
    for (ll c = 1; c < g.size(); ++c) for (ll i = 0; i < g.size(); ++i)
            if (r[i].w != INF) for (ll j = 0; j < g[i].size(); ++j){
        weighted_edge<N> &e = r[g[i][j].first];
        N nw = r[i].w + g[i][j].second;
        if (nw < e.w) e = {i, j, nw};
    }
    vpll todo;
    for (ll i = 0; i < g.size(); ++i) if (r[i].w != INF) for (ll j = 0; j < g[i].size(); ++j)
        if (r[i].w + g[i][j].second < r[g[i][j].first].w) todo.push_back({i, j});
    while (!todo.empty()){
        pll p = todo.back();
        todo.pop_back();
        ll i = g[p.first][p.second].first;
        if (r[i].w == -INF) continue;
        r[i] = {p.first, p.second, -INF};
        for (ll j = 0; j < g[i].size(); ++j) todo.push_back({i, j});
    }
    return r;
}

// Find the minimum weight path between all pairs of nodes in a directed weighted graph in O(n^3) time.
// The graph may have negative edges and negative cycles.
// At position s,t in the output we have {i, j, w} where g[i][j] is the last edge on path from s to t of minimum weight w.
// We have w=INF if no such path exists, w=-INF if the path can have arbitrarily small weight and i=j=-1 if no last edge exists.
template <typename N = ll>
vector<vector<weighted_edge<N>>> floyd_warshall(const weighted_graph<N> &g){
    ll n = g.size();
    vector<vector<weighted_edge<N>>> r(g.size(), vector<weighted_edge<N>>(n, {-1, -1, INF}));
    for (ll i = 0; i < n; ++i){
        r[i][i].w = 0;
        for (ll j = 0; j < g[i].size(); ++j){
            pair<ll, N> p = g[i][j];
            weighted_edge<ll> &e = r[i][p.first];
            if (p.second < e.w) e = {i, j, p.second};
        }
    }
    for (ll k = 0; k < n; ++k) for (ll i = 0; i < n; ++i) for (ll j = 0; j < n; ++j)
            if (r[i][k].w != INF && r[k][j].w != INF && r[i][k].w + r[k][j].w < r[i][j].w){
        r[i][j] = r[k][j];
        r[i][j].w += r[i][k].w;
    }
    for (ll k = 0; k < n; ++k) for (ll i = 0; i < n; ++i) for (ll j = 0; j < n; ++j)
            if (r[i][k].w != INF && r[k][j].w != INF && r[k][k].w < 0){
        r[i][j] = r[k][j];
        r[i][j].w = -INF;
    }
    return r;
}
