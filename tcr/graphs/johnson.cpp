
pair<vector<vector<int>>, vector<vector<NUMBER>>> johnson(vector<unordered_map<int, NUMBER>>& graph){ // O((V + E) log V)
    int n = graph.size();
    unordered_map<int, NUMBER> node;
    for (int i=0; i<n; i++) node[i] = 0;
    graph.push_back(node);
    vector<NUMBER> weights = bellmanFord(graph, n).second;
    graph.pop_back();
    if (weights.size() == 0) return {{}, {}}; // Negative cycle
    for (int i=0; i<n; i++)
        for (auto p : graph[i])
            graph[i][p.first] += weights[i] - weights[p.first];
    vector<vector<int>> dir(n);
    vector<vector<NUMBER>> dist(n);
    for (int i=0; i<n; i++){
        auto p = dijkstra(graph, i);
        for (int j=0; j<n; j++)
            p.second[j] += weights[j] - weights[i];
        dir[i] = p.first;
        dist[i] = p.second;
    }
    return {dir, dist};
}
