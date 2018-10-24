struct dijkstraNode{
    int id;
    int fromID;
    double distance;
};

bool comp(dijkstraNode a, dijkstraNode b){
    return a.distance > b.distance;
}

vector<pair<int, double>> dijkstra(vector<unordered_map<int, double>> graph, int source){
    vector<pair<int, double>> result(graph.size(), {-1, 0});
    vector<bool> visited(graph.size(), false);
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

vector<pair<int, double>> bellmanFord(vector<unordered_map<int, double>> graph, int source){
    vector<pair<int, double>> result(graph.size(), {-1, 0});
    result[source] = {source, 0};

    bool b = false;
    for (int r=0; r<graph.size()-1; r++){
        b = false;
        for (int i=0;i<graph.size();i++){
            if (result[i].first == -1)
                continue;
            for (auto a : graph[i]){
                int j = a.first;
                double d = a.second;
                if (result[i].second + d < result[j].second || result[j].first == -1){
                    result[j].second = result[i].second + d;
                    result[j].first = i;
                    b = true;
                }
            }
        }
        if (!b)
            break;
    }
    if (b)
        return {};
    else
        return result;
}


void testGraphSearch(){
    vector<unordered_map<int, double>> graph(5, (unordered_map<int, double>){});
    graph[0][1] = 3;
    graph[0][2] = 5;
    graph[0][0] = 2;
    graph[1][2] = 1;
    graph[1][3] = 2;
    graph[2][1] = 1;
    graph[2][3] = 5;
    graph[3][0] = 8;
    graph[4][1] = 1;

    printEval(dijkstra(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });
    printEval(bellmanFord(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });

    graph[0][1] = 6;
    graph[1][2] = -2;

    printEval(bellmanFord(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });

    graph[2][1] = 2;

    printEval(bellmanFord(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });

    graph[0][4] = -10;

    printEval(bellmanFord(graph, 0), [](pair<int, double> x){return "(" + tostring(x.first) + " " + tostring(x.second) + ")"; });
}

