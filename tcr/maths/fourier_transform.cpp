
template <typename N = ld>
struct complex_number{
    N x, y;
    
    complex_number(N x_ = 0, N y_ = 0) : x(x_), y(y_) {}
    
    N abs_squared() {return x * x + y * y;}
    
    complex_number operator+ (complex_number z) {return {x + z.x, y + z.y};}
    complex_number operator* (complex_number z) {return {x * z.x - y * z.y, x * z.y + y * z.x};}
    complex_number operator/ (complex_number z) {return {(x * z.x + y * z.y) / z.abs_squared(), (y * z.x - x * z.y) / z.abs_squared()};}
}

// Returns principal n'th root of unity.
complex_number<> complex_root(ll n) {ld a = 2 * CONST_PI / n; return {cosl(a), sinl(a)};}

// Running time O(n*log(n)). The value root must be an n'th root of unity in R, and n must be a power of two.
template <typename R = complex_number<>>
vector<R> discrete_fourier_transform(const vector<R> &xs, R root, ll offset = 0, ll jump = 1){
    ll n = xs.size() / jump;
    if (n == 1) return {xs[offset]};
    vector<R> even = discrete_fourier_transform(xs, root * root, offset, jump * 2),
            odd = discrete_fourier_transform(xs, root * root, offset + jump, jump * 2);
    vector<R> ys(n);
    R w = 1;
    for (ll i = 0; i < n; ++i, w *= root) ys[i] = even[i % (n / 2)] + w * odd[i % (n / 2)];
    return ys;
}

// Running time O(n*log(n)). The value root must be an n'th root of unity in R, and n must be a power of two.
template <typename R = complex_number<>>
vector<R> convolution(const vector<R> &xs1, const vector<R> &xs2, R root){
    ll n = xs1.size();
    vector<R> ys1 = discrete_fourier_transform(xs1, R(1) / root), ys2 = discrete_fourier_transform(xs2, R(1) / root);
    for (ll i = 0; i < n; ++i) ys1[i] *= ys2[i];
    return discrete_fourier_transform(ys1 * ys2, root) / n;
}
