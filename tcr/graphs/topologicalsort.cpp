
vector<int> topologicalSort(vector<vector<int>>& graph){
    vector<int> inCount(graph.size(), 0);
    for (vector<int> node : graph) for (int connection : node) inCount[connection]++;
    queue<int> todo;
    for (int i = 0; i < graph.size(); i++) if (inCount[i] == 0) todo.push(i);
    vector<int> sorted;
    while (!todo.empty()){
        int index = todo.front();
        todo.pop();
        sorted.push_back(index);
        for (int connection : graph[index]){
            inCount[connection]--;
            if (inCount[connection] == 0) todo.push(connection);
        }
    }
    return sorted;
}

// TESTING

void testTopologicalSort(){
    cout << "TOPOLOGICAL SORT" << endl;
    vector<vector<int>> graph = {{3},{0,4},{5,6},{},{0,8},{0,6},{0,3},{1,5},{}};
    cout << topologicalSort(graph) << endl; // {2 7 1 5 4 6 8 0 3}
    cout << endl;
}
