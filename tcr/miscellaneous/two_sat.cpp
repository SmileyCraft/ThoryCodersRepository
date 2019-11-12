
struct two_sat{
    vvll g;

    two_sat(ll n) : g(2 * n) {}

    // Add the implication (i==bi) => (j==bj).
    void implication(ll i, bool bi, ll j, bool bj){
        g[2 * i + !bi].push_back(2 * j + !bj);
        g[2 * j + bj].push_back(2 * i + bi);
    }

    // Find a valid truth assignment of all variables.
    // Note that the truth value of variable i is stored in truths[2*i].
    // Returns an empty vector if no valid truth assignment exists.
    vector<bool> solve(){
        vvll sccs = strongly_connected_components(g);
        vector<bool> truths(g.size());
        for (ll i = sccs.size() - 1; i >= 0; --i) if (!truths[sccs[i][0] ^ 1]) for (ll j : sccs[i]){
            if (truths[j ^ 1]) return {};
            truths[j] = true;
        }
        return truths;
    }
};
