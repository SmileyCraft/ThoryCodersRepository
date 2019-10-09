
// Find the pre- and post-order of the vertices of a directed graph in a depth-first search starting at r in O(m) time.
// If r=-1 then a custom source with an edge to every other node will be used.
struct graph_order{
    const vvll &g;
    ll r;
    vll pre_order, post_order;
    vector<bool> done;

    graph_order(const vvll &g_, ll r_ = -1) : g(g_), r(r_), done(g.size()) {}

    void dfs(ll i){
        if (done[i]) return;
        done[i] = true;
        pre_order.push_back(i);
        for (ll j : g[i]) dfs(j);
        post_order.push_back(i);
    }

    graph_order &run(){
        if (r >= 0) dfs(r);
        else for (ll i = 0; i < g.size(); ++i) dfs(i);
        return *this;
    }

    vll &reverse_pre_order() {reverse(pre_order.begin(), pre_order.end()); return pre_order;}
    vll &reverse_post_order() {reverse(post_order.begin(), post_order.end()); return post_order;}
};
// Order the vertices of a directed acyclic graph such that node i comes before node j whenever there is an edge from i to j in O(m) time.
vll topological_sort(const vvll &g) {return graph_order(g).run().reverse_post_order();}
