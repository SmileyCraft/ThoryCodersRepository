
vector<pair<int, int>> prim(vector<unordered_map<int, NUMBER>> graph, int root = 0){
    auto comp = [graph](pair<int, int> p, pair<int, int> q)mutable{return graph[p.first][p.second] > graph[q.first][q.second];};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
    vector<bool> visited(graph.size(), false);
    vector<pair<int, int>> retval;

    visited[root] = true;
    for (pair<int, NUMBER> nb : graph[root])
        heap.push({root, nb.first});

    while (!heap.empty()){
        pair<int, int> p = heap.top();
        heap.pop();
        if (visited[p.second]) continue;
        visited[p.second] = true;

        retval.push_back(p);
        for (pair<int, NUMBER> nb : graph[p.second])
            if (!visited[nb.first])
                heap.push({p.second, nb.first});
    }

    return retval;
}

// TESTING

void addUndirectedEdge(vector<unordered_map<int, NUMBER>>& graph, int a, int b, NUMBER length){
    graph[a][b] = length;
    graph[b][a] = length;
}

void testPrim(){
    cout << "PRIM" << endl;
    vector<unordered_map<int, NUMBER>> graph(6);
    addUndirectedEdge(graph, 0, 1, 1);
    addUndirectedEdge(graph, 0, 3, 4);
    addUndirectedEdge(graph, 0, 4, 3);
    addUndirectedEdge(graph, 1, 3, 4);
    addUndirectedEdge(graph, 1, 4, 2);
    addUndirectedEdge(graph, 2, 4, 4);
    addUndirectedEdge(graph, 2, 5, 5);
    addUndirectedEdge(graph, 3, 4, 4);
    addUndirectedEdge(graph, 4, 5, 7);
    cout << prim(graph) << endl;
    cout << endl;
}
