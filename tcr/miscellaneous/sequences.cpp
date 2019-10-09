
// Find longest common subsequence in O(nm) time.
template <typename T>
vpll longest_common_subsequence(const vector<T> &xs, const vector<T> &ys){
    ll n = xs.size(), m = ys.size();
    vvll dp(n, vll(m));
    if (xs[0] == ys[0]) dp[0][0] = 1;
    for (ll i = 1; i < n; ++i) dp[i][0] = xs[i] == ys[0] ? 1 : dp[i - 1][0];
    for (ll j = 1; j < m; ++j) dp[0][j] = xs[0] == ys[j] ? 1 : dp[0][j - 1];
    for (ll i = 1; i < n; ++i) for (ll j = 1; j < m; ++j)
        dp[i][j] = xs[i] == ys[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    vpll retval;
    for (ll i = n - 1, j = m - 1; i >= 0 && j >= 0; --i, --j){
        if (xs[i] == ys[j]) retval.emplace_back(i, j);
        else if (i > 0 && dp[i][j] == dp[i - 1][j]) ++j;
        else ++i;
    }
    reverse(retval.begin(), retval.end());
    return retval;
}

// Find longest strictly increasing subsequence in O(n*log(n)) time.
template <typename T>
vll longest_increasing_subsequence(const vector<T> &xs){
    vll prev(xs.size()), best;
    for (ll i = 0; i < xs.size(); i++){
        ll mini = 0, maxi = best.size();
        while (mini < maxi){
            ll mid = (mini + maxi) / 2;
            if (xs[i] <= xs[best[mid]]) maxi = mid;
            else mini = mid + 1;
        }
        if (mini == best.size()) best.push_back(i);
        else best[mini] = i;
        prev[i] = mini == 0 ? -1 : best[mini - 1];
    }
    vll retval;
    for (ll i = best.back(); i >= 0; i = prev[i]) retval.push_back(i);
    reverse(retval.begin(), retval.end());
    return retval;
}
