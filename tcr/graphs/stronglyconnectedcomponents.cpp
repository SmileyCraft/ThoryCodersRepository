
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
