struct edge{
    int n1, n2;
    double length;

    edge(int n1, int n2, double l) : n1(n1), n2(n2), length(l)  {}
};

vector<unordered_map<int, double>> prim(vector<unordered_map<int, double>> graph){
    vector<bool> visited(graph.size(), false);
    vector<unordered_map<int, double>> result(graph.size());

    auto comp = [](edge e1, edge e2){ return e1.length > e2.length; };
    priority_queue<edge, vector<edge>, decltype(comp)> heap(comp);

    for (auto e : graph[0])
        heap.push(edge(0, e.first, e.second));
    visited[0] = true;

    while (!heap.empty()){
        edge e = heap.top();
        heap.pop();

        if (visited[e.n2])
            continue;
        visited[e.n2] = true;
        result[e.n1].insert({e.n2, e.length});
        result[e.n2].insert({e.n1, e.length});

        for (auto nb : graph[e.n2])
            if (!visited[nb.first])
                heap.push(edge(e.n2, nb.first, nb.second));
    }

    return result;
}

void addEdge(vector<unordered_map<int, double>>* graph, int n1, int n2, int length){
    (*graph)[n1].insert({n2, length});
    (*graph)[n2].insert({n1, length});
}

void testPrim(){
    vector<unordered_map<int, double>> graph(6);

    addEdge(&graph, 0, 1, 1);
    addEdge(&graph, 0, 3, 4);
    addEdge(&graph, 0, 4, 3);
    addEdge(&graph, 1, 3, 4);
    addEdge(&graph, 1, 4, 2);
    addEdge(&graph, 2, 4, 4);
    addEdge(&graph, 2, 5, 5);
    addEdge(&graph, 3, 4, 4);
    addEdge(&graph, 4, 5, 7);

    auto mst = prim(graph);

    double span = 0;

    for (int i = 0; i < 6; i++)
        for (auto e : mst[i])
            span += 0.5 * e.second;

    cout << span; // 16
}
