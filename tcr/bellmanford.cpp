
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

// TESTING

void testBellmanFord(){
    cout << "BELLMAN FORD" << endl;
    vector<unordered_map<int, NUMBER>> graph = {{{0,2},{1,3},{2,5}},{{2,1},{3,2}},{{1,1},{3,5}},{{0,8},{1,1}},{}};
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 3} {1 4} {1 5} {-1 -1}}
    graph[0][1] = 6;
    graph[1][2] = -2;
    cout << bellmanFord(graph, 0) << endl; // {}
    graph[2][1] = 2;
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 6} {1 4} {1 8} {-1 -1}}
    graph[0][4] = -10;
    cout << bellmanFord(graph, 0) << endl; // {{0 0} {0 6} {1 4} {1 8} {0 -10}}
    cout << endl;
}
