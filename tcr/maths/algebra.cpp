
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

// Returns {x, y} such that ax+by=gcd(a,b) in O(log(min(a,b))) time.
pll extended_euclid(ll a, ll b){
    if (b == 0) return {1, 0};
    pll p = extended_euclid(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

// Running time O(log(n)).
ll mod_inverse(ll n, ll m) {return (extended_euclid(n, m).first + m) % m;}

// Returns 0<=y<m1*m2 such that y===x1 (mod m1) and y===x2 (mod m2).
// If m1 and m2 are not coprime, divide the answer by their greatest common divisor and verify the result.
// Requires both m1*m1 and m2*m2 to not overflow.
// Otherwise, consider brute force CRT: Just keep adding the larger modulus until it works.
ll chinese_remainder_theorem(ll x1, ll m1, ll x2, ll m2){
    pll p = extended_euclid(m1, m2);
    ll m = m1 * m2;
    return ((x1 * p.second % m1 * m2 + x2 * p.first % m2 * m1) % m + m) % m;
}
