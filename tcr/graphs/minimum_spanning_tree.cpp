
// Find the minimum weight spanning tree of a non-empty undirected weighted connected graph in O(m*log(m)) time.
// An edge {i, j, w} in the output corresponds to the edge g[i][j] with weight w.
template <typename N = ll>
vector<weighted_edge<N>> minimum_spanning_tree(const weighted_graph<N> &g){
    vector<bool> visited(g.size());
    vector<weighted_edge<N>> r;
    priority_queue<weighted_edge<N>, vector<weighted_edge<N>>, greater<weighted_edge<N>>> q;
    visited[0] = true;
    for (ll i = 0; i < g[0].size(); ++i) q.push({0, i, g[0][i].second});
    while (!q.empty()){
        weighted_edge<N> e = q.top(); q.pop();
        ll t = g[e.i][e.j].first;
        if (visited[t]) continue;
        visited[t] = true;
        r.push_back(e);
        for (ll i = 0; i < g[t].size(); ++i) q.push({t, i, g[t][i].second});
    }
    return r;
}
