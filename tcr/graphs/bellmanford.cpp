
pair<vector<int>, vector<NUMBER>> bellmanFord(vector<unordered_map<int, NUMBER>>& graph, int source){ // O(VE)
    int n = graph.size();
    vector<int> dir(n, -1);
    vector<NUMBER> dist(n, 0);
    dir[source] = source;
    bool b = false;
    for (int r = 0; r < n - 1; r++){
        b = false;
        for (int i = 0; i < n; i++){
            if (dir[i] == -1) continue;
            for (auto a : graph[i]){
                int j = a.first;
                NUMBER d = a.second;
                if (dist[i] + d < dist[j] || dir[j] == -1){
                    dist[j] = dist[i] + d;
                    dir[j] = i;
                    b = true;
                }
            }
        }
        if (!b) break;
    }
    if (b) return {{}, {}};
    else return {dir, dist};
}
