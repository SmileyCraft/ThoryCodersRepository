
vector<string> split_by(string s, const string &t){
    s += t;
    vector<string> v;
    string c;
    for (ll i = 0; i < s.length(); ++i){
        if (s.substr(i, t.length()) == t){
            v.push_back(c);
            c = "";
            i += t.length() - 1;
        }
        else c += s[i];
    }
    return v;
}

// Knuth Morris Pratt
vll kmp_automaton(const string &s){
    vll retval(s.length());
    for (ll i = 1; i < retval.size(); ++i){
        retval[i] = retval[i - 1] + 1;
        while (retval[i] > 0 && s[i] != s[retval[i] - 1]) retval[i] = retval[i] == 1 ? 0 : retval[retval[i] - 2] + 1;
    }
    return retval;
}
