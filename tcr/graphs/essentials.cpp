
template <typename N = ll>
struct weighted_edge{
    ll i, j; N w; // from, to, weight
    weighted_edge(ll i_ = -1, ll j_ = -1, N w_ = -1) : i(i_), j(j_), w(w_) {}
};

template <typename N = ll>
using weighted_graph = vector<vector<pair<long long, N>>>;

template <typename N = ll>
struct flow_edge{
    ll j, r; N c, f; // to, reverse, capacity, flow
    flow_edge(ll j_, ll r_, N c_) : j(j_), r(r_), c(c_), f(0) {}
};

template <typename N = ll>
struct flow_graph : vector<vector<flow_edge<N>>>{
	flow_graph(ll n = 0) : vector<vector<flow_edge<N>>>(n) {}
	void add_edge(ll i, ll j, N c){
	    auto &t = *this;
		t[i].emplace_back(j, t[j].size(), c);
		t[j].emplace_back(i, t[i].size() - 1, c);
	}
	void add_arc(ll i, ll j, N c){
	    auto &t = *this;
		t[i].emplace_back(j, t[j].size(), c);
		t[j].emplace_back(i, t[i].size() - 1, 0);
	}
};

template <typename N = ll, typename M = N>
struct cost_flow_edge{
    ll j, r; N c, f; M a; // to, reverse, capacity, flow, cost
    cost_flow_edge(ll j_, ll r_, N c_, M a_) : j(j_), r(r_), c(c_), f(0), a(a_) {}
};

template <typename N = ll, typename M = N>
struct cost_flow_graph : vector<vector<cost_flow_edge<N, M>>>{
	cost_flow_graph(ll n = 0) : vector<vector<cost_flow_edge<N, M>>>(n) {}
	void add_arc(ll i, ll j, N c, M a){
	    auto &t = *this;
		t[i].emplace_back(j, t[j].size(), c, a);
		t[j].emplace_back(i, t[i].size() - 1, 0, -a);
	}
};
