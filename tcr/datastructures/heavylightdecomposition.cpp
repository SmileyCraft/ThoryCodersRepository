
struct HLD{
    vector<vector<int>> g;
    int n, r; //node count, root
    vector<int> p, pr, h, d; //parent, path-root, heavy child, depth

    int dfs(int u){
        int s = 1, ss, bss = 0;
        for (int v : g[u]) if (v != p[u]){
            d[v] = d[u] + 1;
            p[v] = u;
            s += ss = dfs(v);
            if (ss > bss){
                bss = ss;
                h[u] = v;
            }
        }
        return s;
    }

    HLD(vector<vector<int>> g, int r = 0) : g(g), n(g.size()), r(r), p(n, -1), pr(n), h(n, -1), d(n, 0) {
        dfs(r);
        for (int i = 0; i < n; i++) if (p[i] == -1 || i != h[p[i]]) for (int j = i; j != -1; j = h[j]) pr[j] = i;
    }

    int lca(int u, int v){
        for (; pr[u] != pr[v]; u = p[pr[u]]) if (d[pr[u]] < d[pr[v]]) swap(u, v);
        return d[u] < d[v] ? u : v;
    }
};
