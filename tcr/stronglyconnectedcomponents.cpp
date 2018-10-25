
vector<vector<int>> stronglyConnectedComponents(vector<vector<int>>& graph){
    int n = graph.size();
    stack<int> leaveOrder;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        visited[i] = true;
        stack<int> dfs, nextConnection;
        dfs.push(i);
        nextConnection.push(0);
        while (!dfs.empty()){
            if (nextConnection.top() == graph[dfs.top()].size()){
                leaveOrder.push(dfs.top());
                dfs.pop();
                nextConnection.pop();
            }
            else{
                int connection = graph[dfs.top()][nextConnection.top()];
                nextConnection.top()++;
                if (!visited[connection]){
                    visited[connection] = true;
                    dfs.push(connection);
                    nextConnection.push(0);
                }
            }
        }
    }
    vector<vector<int>> reverseGraph(n);
    for (int i = 0; i < n; i++){
        for (int j : graph[i]) reverseGraph[j].push_back(i);
        visited[i] = false;
    }
    vector<vector<int>> sccs;
    while (!leaveOrder.empty()){
        int node = leaveOrder.top();
        leaveOrder.pop();
        if (visited[node]) continue;
        visited[node] = true;
        sccs.emplace_back(1, node);
        queue<int> bfs;
        bfs.push(node);
        while (!bfs.empty()){
            for (int connection : reverseGraph[bfs.front()]){
                if (!visited[connection]){
                    visited[connection] = true;
                    sccs.back().push_back(connection);
                    bfs.push(connection);
                }
            }
            bfs.pop();
        }
    }
    return sccs;
}

// TESTING

void testStronglyConnectedComponents(){
    cout << "STRONGLY CONNECTED COMPONENTS" << endl;
    vector<vector<int>> graph = {{1,4},{2,4},{3},{2,7},{5},{1,6},{2},{6}};
    cout << stronglyConnectedComponents(graph) << endl; // {{0} {1 5 4} {2 3 6 7}}
    graph = {{3,5,6},{2},{1,3},{0,2,4},{3},{0,8},{7},{8},{6,10},{8},{9},{4,14,15},{4,11,13},{14},
            {12,13,17},{17},{8,15},{19},{10,16},{18},{13,22},{20},{13,20,21}};
    cout << stronglyConnectedComponents(graph) << endl; // {{20 21 22} {11 12 14 13} {17 15 16 18 19} {0 3 5 2 4 1} {8 7 9 6 10}}
    cout << endl;
}
