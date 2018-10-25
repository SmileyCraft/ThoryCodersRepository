
vector<pair<int, NUMBER>> bellmanFord(vector<unordered_map<int, NUMBER>>& graph, int source){
    vector<pair<int, NUMBER>> retval(graph.size(), {-1, -1});
    retval[source] = {source, 0};
    bool b = false;
    for (int r = 0; r < graph.size() - 1; r++){
        b = false;
        for (int i = 0; i < graph.size(); i++){
            if (retval[i].first == -1) continue;
            for (auto a : graph[i]){
                int j = a.first;
                NUMBER d = a.second;
                if (retval[i].second + d < retval[j].second || retval[j].first == -1){
                    retval[j].second = retval[i].second + d;
                    retval[j].first = i;
                    b = true;
                }
            }
        }
        if (!b) break;
    }
    if (b) return {};
    else return retval;
}
