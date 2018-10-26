
template <class T>
vector<pair<int, int>> longestCommonSubsequence(vector<T> a, vector<T> b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n);
    (dp[0] = {a[0] == b[0] ? 1 : 0}).resize(m);
    for (int i = 1; i < n; i++)
        (dp[i] = {a[i] == b[0] ? 1 : dp[i - 1][0]}).resize(m);
    for (int j = 1; j < m; j++)
        dp[0][j] = a[0] == b[j] ? 1 : dp[0][j - 1];
    for (int i = 1; i < n; i++) for (int j = 1; j < m; j++)
        dp[i][j] = a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    vector<pair<int, int>> retval;
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--){
        if (a[i] == b[j])
            retval.emplace_back(i, j);
        else if (i > 0 && dp[i][j] == dp[i - 1][j])
            j++;
        else
            i++;
    }
    reverse(retval.begin(), retval.end());
    return retval;
}
