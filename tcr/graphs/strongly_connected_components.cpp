
// Find the strongly connected components of a directed graph in topological order in O(m) time.
vvll strongly_connected_components(const vvll &g){
    vvll r, rg(g.size()); // reverse graph
    for (ll i = 0; i < g.size(); ++i) for (ll j : g[i]) rg[j].push_back(i);
    vector<bool> done(g.size());
    vll todo;
    for (ll s : topological_sort(g)) if (!done[s]){
        r.emplace_back(0);
        todo.push_back(s);
        while (!todo.empty()){
            ll i = todo.back(); todo.pop_back();
            if (done[i]) continue;
            done[i] = true;
            r.back().push_back(i);
            for (ll j : rg[i]) todo.push_back(j);
        }
    }
    return r;
}
