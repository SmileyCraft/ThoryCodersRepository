
vector<int> hopcroftKarp(vector<vector<int>> graph){
    int n = graph.size();
    vector<int> uPair(n, -1);
    unordered_map<int, int> vPair;
    bool done = false;
    while (!done){
        vector<bool> visited(n, false);
        queue<int> q;
        done = true;
        for (int u = 0; u < n; u++)
            if (uPair[u] == -1)
                q.push(u);
        while (!q.empty()){
            int u = q.front();
            q.pop();
            visited[u] = true;
            for (int v : graph[u]){
                if (!vPair.count(v)) done = false;
                else{
                    if (visited[vPair[v]]) continue;
                    uPair[vPair[v]] = -1;
                    q.push(vPair[v]);
                }
                uPair[u] = v;
                vPair[v] = u;
                break;
            }
        }
    }
    return uPair;
}
