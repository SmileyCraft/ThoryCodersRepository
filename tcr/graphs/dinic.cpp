
void addBackwardsArrows(vector<unordered_map<int, NUMBER>>& c){
    for (int i = 0; i < c.size(); i++)
        for (pair<int, NUMBER> p : c[i])
            if (!c[p.first].count(i))
                c[p.first][i] = 0;
}

vector<int> levelGraph(vector<unordered_map<int, NUMBER>>& c, vector<unordered_map<int, NUMBER>>& f, int s){
    vector<int> l(f.size(), -1);
    l[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (pair<int, NUMBER> p : c[u]){
            if (f[u][p.first] < p.second && l[p.first] < 0){
                l[p.first] = l[u] + 1;
                q.push(p.first);
            }
        }
    }
    return l;
}

NUMBER bf(vector<unordered_map<int, NUMBER>>& c, vector<unordered_map<int, NUMBER>>& f, vector<int>& l, int s, NUMBER inFlow, int t){
    if (s == t) return inFlow;
    NUMBER flow = 0;
    for (pair<int, NUMBER> p : c[s]){
        if (f[s][p.first] < p.second && l[s] < l[p.first]){
            NUMBER outFlow = bf(c, f, l, p.first, min(inFlow - flow, p.second - f[s][p.first]), t);
            f[s][p.first] += outFlow;
            f[p.first][s] -= outFlow;
            flow += outFlow;
        }
        if (flow == inFlow) break;
    }
    return flow;
}

vector<unordered_map<int, NUMBER>> dinic(vector<unordered_map<int, NUMBER>> c, int s, int t){
    addBackwardsArrows(c);
    vector<unordered_map<int, NUMBER>> f = c;
    for (int i = 0; i < f.size(); i++)
        for (pair<int, NUMBER> p : f[i])
            f[i][p.first] = 0;
    while(true){
        vector<int> l = levelGraph(c, f, s);
        if (l[t] < 0) return f;
        bf(c, f, l, s, INF, t);
    }
}

vector<pair<int, int>> minCut(vector<unordered_map<int, NUMBER>> c, int s, int t){
    vector<unordered_map<int, NUMBER>> f = dinic(c, s, t);
    vector<int> l = levelGraph(c, f, s);
    vector<pair<int, int>> cut;
    for (int i = 0; i < c.size(); i++){
        if(l[i] < 0) continue;
        for (pair<int, NUMBER> p : c[i])
            if(l[p.first] < 0)
                cut.push_back({i, p.first});
    }
    return cut;
}
