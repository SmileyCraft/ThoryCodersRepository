
void minCostFlow(vector<unordered_map<int, NUMBER>>& f, vector<unordered_map<int, NUMBER>> c, vector<unordered_map<int, NUMBER>> a){
    int n = c.size();
    for (auto& m : f)
        for (auto& p : m)
            if (p.second < 0) p.second = 0;
    while (true){
        vector<vector<NUMBER>> dp(n, vector<NUMBER>(n + 1, 0));
        vector<vector<int>> dpp(n, vector<int>(n + 1, -1));
        vector<vector<bool>> dpb(n, vector<bool>(n + 1, false));
        for (int j = 1; j <= n; j++){
            for (int i = 0; i < n; i++){
                for (auto p : f[i]){
                    if (f[p.first][i] < c[p.first][i] || p.second > 0){
                        NUMBER x;
                        bool b = p.second == 0 || (a[p.first][i] < -a[i][p.first] && f[p.first][i] < c[p.first][i]);
                        if (b) x = dp[p.first][j - 1] + a[p.first][i];
                        else x = dp[p.first][j - 1] - a[i][p.first];
                        if (x < dp[i][j]){
                            dp[i][j] = x;
                            dpp[i][j] = p.first;
                            dpb[i][j] = b;
                        }
                    }
                }
            }
        }
        int bi;
        NUMBER l = 0;
        for (int i = 0; i < n; i++){
            NUMBER li = dp[i][n] - dp[i][n - 1];
            for (int j = 0; j < n - 1; j++)
                li = max(li, (dp[i][n] - dp[i][j]) / (n - j));
            if (li < l){
                bi = i;
                l = li;
            }
        }
        if (l > -0.000000001) break;
        unordered_map<int, int> m;
        vector<int> p;
        vector<bool> b;
        for (int j = n; !m.count(bi); j--){
            m[bi] = p.size();
            p.push_back(bi);
            b.push_back(dpb[bi][j]);
            bi = dpp[bi][j];
        }
        p.push_back(bi);
        NUMBER mr = INF;
        for (int i = p.size() - 1; i > m[bi]; i--){
            if (b[i - 1]) mr = min(mr, c[p[i]][p[i - 1]] - f[p[i]][p[i - 1]]);
            else mr = min(mr, f[p[i - 1]][p[i]]);
        }
        for (int i = p.size() - 1; i > m[bi]; i--){
            if (b[i - 1]) f[p[i]][p[i - 1]] += mr;
            else f[p[i - 1]][p[i]] -= mr;
        }
    }
}
