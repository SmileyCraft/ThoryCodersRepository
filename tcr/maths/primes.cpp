
// Time complexity O(n).
vll primes, spf;
void sieve(ll n){
    spf.assign(n + 1, -1);
    for (ll i = 2; i <= n; ++i){
        if (spf[i] == -1){
            primes.push_back(i);
            spf[i] = i;
        }
        for (ll p : primes){
            if (i * p > n) break;
            spf[i * p] = p;
            if (p == spf[i]) break;
        }
    }
}
