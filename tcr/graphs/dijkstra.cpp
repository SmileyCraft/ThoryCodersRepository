
struct dijkstraNode{
    int id, fromID;
    NUMBER distance;
    bool operator> (const dijkstraNode other) const {return distance > other.distance;}
};

pair<vector<int>, vector<NUMBER>> dijkstra(vector<unordered_map<int, NUMBER>>& graph, int source){ // O((V + E) log V)
    vector<bool> visited(graph.size(), false);
    vector<int> dir(graph.size(), -1);
    vector<NUMBER> dist(graph.size(), 0);
    priority_queue<dijkstraNode, vector<dijkstraNode>, greater<dijkstraNode>> heap;

    heap.push({source, source, 0});
    while (!heap.empty()){
        dijkstraNode node = heap.top();
        heap.pop();
        if (visited[node.id]) continue;
        visited[node.id] = true;

        dir[node.id] = node.fromID;
        dist[node.id] = node.distance;
        for(auto i : graph[node.id])
            if (!visited[i.first])
                heap.push({i.first, node.id, node.distance + i.second});
    }

    return {dir, dist};
}
