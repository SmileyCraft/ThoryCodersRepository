
vector<int> automaton(string s){
    vector<int> autom(s.length(), 0);
    for (int i = 1; i < autom.size(); i++){
        autom[i] = autom[i - 1] + 1;
        while (autom[i] > 0 && s[i] != s[autom[i] - 1]){
            autom[i] = autom[i] == 1 ? 0 : autom[autom[i] - 2] + 1;
        }
    }
    return autom;
}

vector<int> matchStrings(string a, string b){
    vector<int> autom = automaton(b + "@" + a);
    vector<int> matchCounts(a.length());
    for (int i = 0; i < matchCounts.size(); i++)
        matchCounts[i] = autom[i + b.length() + 1];
    return matchCounts;
}

long long charVal(char c) {return c - 'a';}

int firstHashMatch(string a, string b){
    if (a.length() < b.length()) return -1;
    long long mod = 1000000007; // 10^9 + 7 9 21 33 87 are primes
    long long base = 37; // Generating elements for 10^9+7: 37, 38, 39, 40, 41, for 10^9+87: 31, 37, 40, 47, 48
    long long bHash = 0;
    for (char c : b){
        bHash *= base;
        bHash += charVal(c);
        bHash %= mod;
    }
    long long aHash = 0;
    long long powB = 1;
    for (int i = 0; i < b.length(); i++){
        aHash *= base;
        aHash += charVal(a[i]);
        aHash %= mod;
        powB *= base;
        powB %= mod;
    }
    if (aHash == bHash) return 0;
    for (int i = 0; i + b.length() < a.length(); i++){
        aHash *= base;
        aHash += charVal(a[i + b.length()]) + base * mod - powB * charVal(a[i]);
        aHash %= mod;
        if (aHash == bHash) return i + 1;
    }
    return -1;
}
