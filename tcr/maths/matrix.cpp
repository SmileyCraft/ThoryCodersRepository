
template <typename R = ld>
struct matrix{
    vector<vector<R>> c;

    matrix(const vector<vector<R>> &c_) : c(c_) {}
    matrix(ll n, ll m) : c(n, vector<R>(m)) {}
    
    vector<R> &operator[] (ll i) {return c[i];}
    matrix<R> operator* (const matrix<R> &m){
        matrix<R> retval(c.size(), m[0].size());
        for (ll i = 0; i < c.size(); ++i) for (ll j = 0; j < c[0].size(); ++j) for (ll k = 0; k < m.c[0].size(); ++k) retval[i][k] += c[i][j] * m[j][k];
        return retval;
    }

    // Put matrix M in reduced row echelon form R and calculate determinant, rank, and inverse matrix I such that R=I*M.
    // When called, det should be 1, ran should be 0, inv should be the identity matrix.
    // Time complexity O(n^3) and space complexity O(n^2).
    matrix<R> &gaussian_elimination(R &det, ll &ran, matrix<R> &inv){
        ll n = c.size(), m = c[0].size();
        for (ll i = 0, j = 0; i < n && j < m; ++j){
            ll k = i;
            while (k < n && c[k][j] == 0) ++k;
            if (k == n) continue;
            if (i != k) {det *= -1; swap(c[i], c[k]); swap(inv.c[i], inv.c[k]);}
            R x = c[i][j];
            det *= x; c[i] /= x; inv.c[i] /= x;
            for (k = 0; k < n; ++k) if (i != k) {inv.c[k] -= inv.c[i] * c[k][j]; c[k] -= c[i] * c[k][j];}
            ++i; ++ran;
        }
        return *this;
    }
};
