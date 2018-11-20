
bool prime(int n){
    if (n == 1) return false;
    if (n == 2) return true;
    if (!(n&1)) return false;
    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

vector<bool> sieve(int n){
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    for (int i = 4; i < n; i += 2) primes[i] = false;
    for (int i = 3; i * i < n; i += 2) for (int j = i; i * j < n; j += 2) primes[i * j] = false;
    return primes;
}

unordered_map<int, int> factorize(int n){
    unordered_map<int, int> factors;
    if (!(n&1)){
        factors[2] = 0;
        while (!(n&1)){
            factors[2]++;
            n >>= 1;
        }
    }
    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0){
            factors[i] = 0;
            while (n % i == 0){
                factors[i]++;
                n /= i;
            }
        }
    }
    if (n > 1) factors[n] = 1;
    return factors;
}

vector<unordered_map<int, int>> factorSieve(int n){
    vector<unordered_map<int, int>> factorizations(n);
    for (int i = 1; (i << 1) < n; i++){
        factorizations[i << 1][2] = 1;
        if (factorizations[i].count(2))
            factorizations[i << 1][2] += factorizations[i][2];
    }
    for (int p = 3; p < n; p++){
        if (factorizations[p].empty()){
            for (int i = 1; i * p < n; i++){
                factorizations[i * p][p] = 1;
                if (factorizations[i].count(p))
                    factorizations[i * p][p] += factorizations[i][p];
            }
        }
    }
    return factorizations;
}

int eulerPhi(int x){
    unordered_map<int, int> factors = factorize(x);
    for (pair<int, int> factor : factors){
        x /= factor.first;
        x *= factor.first - 1;
    }
    return x;
}
