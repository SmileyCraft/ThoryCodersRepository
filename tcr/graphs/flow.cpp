
// Find the maximum flow in a flow graph from s to t in O(n^2*m) time.
// The running time reduces to O(min{V^(2/3),E^(1/2)}*E) if all edges have unit capacities.
// If additionally each vertex, except s and t, has either a single incoming edge or a single outgoing edge, this reduces to O(V^(1/2)*E).
template <typename N = ll>
struct dinic{
    flow_graph<N> &g;
    ll s, t; N flow;
    vll level;
    vector<typename vector<flow_edge<N>>::iterator> its;

    dinic(flow_graph<N> &g_, ll s_, ll t_) : g(g_), s(s_), t(t_), flow(0), level(g.size()), its(g.size()) {}

    N augment(ll i, N x){
        if (i == t) return x;
        N s = 0;
        for (; its[i] != g[i].end(); ++its[i]){
            flow_edge<N> &e = *its[i];
            if (e.f == e.c || level[e.j] != level[i] + 1) continue;
            N aug = augment(e.j, min(x, e.c - e.f));
            if (aug == 0) continue;
            e.f += aug; g[e.j][e.r].f -= aug; s += aug; x -= aug;
            if (x == 0) break;
        }
        return s;
    }

    dinic &run(){
        while (true){
            fill(level.begin(), level.end(), -1); level[s] = 0;
            queue<ll> todo; todo.push(s);
            while (!todo.empty()){
                ll i = todo.front(); todo.pop();
                its[i] = g[i].begin();
                for (flow_edge<N> e : g[i]) if (e.f < e.c && level[e.j] == -1) {level[e.j] = level[i] + 1; todo.push(e.j);}
            }
            if (level[t] == -1) return *this;
            flow += augment(s, INF);
        }
    }

    // Find the set S containing s but not t such that the total capacity of all edges from inside S to outside S is minimized.
    // Requires the maximum flow to have been found and runs in O(E) time.
    vll min_cut(){
        vll r = {s};
        vector<bool> done(g.size()); done[s] = true;
        for (ll i = 0; i < r.size(); ++i) for (flow_edge<N> e : g[r[i]]) if (e.f < e.c && !done[e.j]) {r.push_back(e.j); done[e.j] = true;}
        return r;
    }
};

// Find the minimum cost maximum flow in a cost flow graph from s to t in O(m*(n+log(m)*f)) time.
// Here f is the number of iterations, which is bounded by the value of the maximum flow.
// There must not be a negative cost cycle and all vertices must be reachable from s.
template <typename N = ll, typename M = N>
pair<N, M> min_cost_max_flow(cost_flow_graph<N, M> &g, ll s, ll t){
    vector<M> pot(g.size(), INF); pot[s] = 0;
    for (ll c = 0; c < g.size(); ++c) for (ll i = 0; i < g.size(); ++i)
            if (pot[i] != INF) for (cost_flow_edge<N, M> e : g[i]) if (e.f < e.c)
        pot[e.j] = min(pot[e.j], pot[i] + e.a);
    N tf = 0; M tc = 0;
    while (true){
        vector<weighted_edge<M>> d(g.size());
        vector<N> aug(g.size());
        priority_queue<weighted_edge<M>, vector<weighted_edge<M>>, greater<weighted_edge<M>>> q;
        q.push({-1, -1, 0});
        while (!q.empty()){
            weighted_edge<M> e = q.top(); q.pop();
            ll v = e.i == -1 ? s : g[e.i][e.j].j;
            if (d[v].w != -1) continue;
            d[v] = e;
            aug[v] = e.i == -1 ? INF : min(aug[e.i], g[e.i][e.j].c - g[e.i][e.j].f);
            for (ll i = 0; i < g[v].size(); ++i) if (g[v][i].f < g[v][i].c)
                q.push({v, i, e.w + g[v][i].a + pot[v] - pot[g[v][i].j]});
        }
        if (d[t].w == -1) return {tf, tc};
        tf += aug[t];
        for (ll i = t; i != s; i = d[i].i){
            cost_flow_edge<N, M> &e = g[d[i].i][d[i].j];
            e.f += aug[t]; g[i][e.r].f -= aug[t];
            tc += aug[t] * e.a;
        }
        for (ll i = 0; i < g.size(); ++i) if (d[i].w != -1) pot[i] += d[i].w;
    }
}
