
// Prefix sum tree. Use one-based indices.
template <typename T>
struct fenwick_tree{
	vector<T> t;

	fenwick_tree(ll n) : t(n + 1) {}

	// Calculate prefix sum up and till the i'th entry in O(log(n)) time.
	T query(ll i){
		T s = 0;
		for(; i > 0; i -= (i & (-i))) s += t[i];
		return s;
	}
	T query(ll l, ll r) {return query(r) - query(l - 1);}

	// Increment the i'th entry by v in O(log(n)) time.
	void increment(ll i, T v){
		for(; i < t.size(); i += (i & (-i))) t[i] += v;
	}
};

// Two dimensional prefix sum tree. Use one-based indices.
template <typename T>
struct fenwick_tree_2d{
    vector<vector<T>> t;

    fenwick_tree_2d(ll n, ll m) : t(n + 1, vector<T>(m + 1)) {}

    // Calculate prefix sum up and till entry (i,j) in O(log^2(n)) time.
    T query(ll i, ll j){
        T s = 0;
        for (ll x = i; x > 0; x -= (x & (-x))) for (ll y = j; y > 0; y -= (y & (-y))) s += t[x][y];
        return s;
    }
    T query(ll i1, ll i2, ll j1, ll j2){
        return query(i2, j2) - query(i2, j1 - 1) - query(i1 - 1, j2) + query(i1 - 1, j1 - 1);
    }

    // Increment entry (i,j) by v in O(log^2(n)) time.
    void increment(ll i, ll j, T v){
        for (ll x = i; x < t.size(); x += (x & (-x))) for (ll y = j; y < t[x].size(); y += (y & (-y))) t[x][y] += v;
    }
};
