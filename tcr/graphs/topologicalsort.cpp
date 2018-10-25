
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
