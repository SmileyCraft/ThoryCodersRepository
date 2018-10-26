vector<int> hopcroftKarp(vector<vector<int>> graph, int U, int V){
    vector<int> uPair(U, -1);
    vector<int> vPair(V, -1);
    bool done = false;
    while (!done){
        vector<bool> visited(U, false);
        queue<int> q;
        done = true;
        for (int u = 0; u < U; u++)
            if (uPair[u] == -1)
                q.push(u);
        while (!q.empty()){
            int u = q.front();
            q.pop();
            visited[u] = true;
            for (int v : graph[u]){
                if (vPair[v] == -1){
                    uPair[u] = v;
                    vPair[v] = u;
                    done = false;
                    break;
                }
                else if (!visited[vPair[v]]){
                    uPair[vPair[v]] = -1;
                    q.push(vPair[v]);
                    uPair[u] = v;
                    vPair[v] = u;
                    break;
                }
            }
        }
    }
    return uPair;
}

void testHopcroftKarp(){
    vector<vector<int>> graph(5);
    graph[0] = {0, 1};
    graph[1] = {0, 4};
    graph[2] = {2, 3};
    graph[3] = {0, 4};
    graph[4] = {1, 3};
    vector<int> matching = hopcroftKarp(graph, 5, 5);
    for (int i = 0; i < 5; i++)
        cout << matching[i] << ' ';
    cout << endl; // 1 4 2 0 3
}
