
// Interval query data structure.
// When op is a lambda expression, use 'decltype(op)' as template parameter for F.
template <typename T, typename F>
struct segment_tree{
    ll n; vector<T> t; T id; F op;

    segment_tree(ll n_, T id_, F op_) : n(n_), t(2 * n_, id_), id(id_), op(op_) {}

    // Change the i'th value to v in O(log(n)) time.
    void update(ll i, T v){
        for (t[i + n] = v, i = (i + n) / 2; i > 0; i /= 2) t[i] = op(t[2 * i], t[2 * i + 1]);
    }

    // Calculate the combined value from the a'th value up and till the b'th value in O(log(n)) time.
    T query(ll a, ll b){
        T l = id, r = id;
		for (a += n, b += n; a < b; a /= 2, b /= 2) {
			if (a & 1) l = op(l, t[a++]);
			if (!(b & 1)) r = op(t[b--], r);
		}
		return op(a == b ? op(l, t[a]) : l, r);
    }
};
