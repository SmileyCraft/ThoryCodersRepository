
// Disjoint set data structure.
struct union_find{
    vll p, s;

    union_find(ll n) : p(n), s(n, 1) {for (ll i = 0; i < n; ++i) p[i] = i;}

    // Look up the id of the set containing i in O(alpha(n)) amortized time.
    ll look_up(ll i) {return i == p[i] ? i : (p[i] = look_up(p[i]));}

    // Merge the sets containing i and j in O(alpha(n)) amortized time.
    void combine(ll i, ll j){
        i = look_up(i); j = look_up(j);
        if (i == j) return;
        if (s[i] < s[j]) swap(i, j);
        p[j] = i; s[i] += s[j];
    }
};
