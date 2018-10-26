
template <class T>
vector<pair<int, int>> longestCommonSubsequence(vector<T> a, vector<T> b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(a.size());
    for (int i = 0; i < n; i++)
        dp[i].push_back(a[i] == b[0] ? 1 : 0);
    for (int j = 1; j < m; j++)
        dp[0].push_back(a[0] == b[j] ? 1 : 0);
    for (int i = 1; i < n; i++) for (int j = 1; j < m; j++)
        dp[i][j] = a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    vector<pair<int, int>> retval;
    for (pair<int, int> p = {n - 1, m - 1}; p.first >= 0 && p.second >= 0; ){
        if (a[p.first] == b[p.second])
            retval.push_back(p);
        else if (p.first > 0 && dp[p.first][p.second] == dp[p.first - 1][p.second])
            p.second++;
        else
            p.first++;
        p.first--;
        p.second--;
    }
    reverse(retval.begin(), retval.end());
    return retval;
}
