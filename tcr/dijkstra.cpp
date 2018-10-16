struct dijkstraNode{
    int id;
    int fromID;
    double distance;
};

bool comp(dijkstraNode a, dijkstraNode b){
    return a.distance > b.distance;
}

vector<pair<int, double>> dijkstra(vector<unordered_map<int, double>> graph, int source){
    vector<bool> visited(graph.size(), false);
    vector<pair<int, double>> result(graph.size(), {-1, -1});
    priority_queue<dijkstraNode, vector<dijkstraNode>, function<bool(dijkstraNode, dijkstraNode)>> heap(comp);

    heap.push({source, source, 0});

    while (!heap.empty()){
        dijkstraNode node = heap.top();
        heap.pop();

        if (visited[node.id])
            continue;
        visited[node.id] = true;
        result[node.id] = {node.fromID, node.distance};

        for(auto i : graph[node.id]){
            if (!visited[i.first])
                heap.push({i.first, node.id, node.distance + i.second});
        }
    }

    return result;
}

void testDijkstra(){
    vector<unordered_map<int, double>> graph(5);
    unordered_map<int, double> m0;
    m0.insert({1, 3});
    m0.insert({2, 5});
    m0.insert({0, 2});
    unordered_map<int, double> m1;
    m1.insert({2, 1});
    m1.insert({3, 2});
    unordered_map<int, double> m2;
    m2.insert({1, 1});
    m2.insert({3, 5});
    unordered_map<int, double> m3;
    m3.insert({0, 8});
    unordered_map<int, double> m4;
    m3.insert({1, 1});

    graph[0] = m0;
    graph[1] = m1;
    graph[2] = m2;
    graph[3] = m3;
    graph[4] = m4;

    printEval(dijkstra(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });
}
