
//sort non-intersecting open line segments satisfying the canonical partial ordering from bottom to top in O(n log n) time
vector<int> sortLineSegments(vector<line> ls){
    int n = ls.size();
    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++){
        line& l = ls[i];
        if (l.p.x > l.q.x) swap(l.p, l.q);
        if (l.p.x == l.q.x) ps.push_back({i, 1});
        else{
            ps.push_back({i, 0});
            ps.push_back({i, 2});
        }
    }
    sort(ps.begin(), ps.end(), [&ls](pair<int, int> p1, pair<int, int> p2){
        line l1 = ls[p1.first], l2 = ls[p2.first];
        NUMBER x1 = (p1.second ? l1.p : l1.q).x, x2 = (p2.second ? l2.p : l2.q).x;
        return x1 == x2 ? (p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second) : x1 < x2;
    });

    auto comp = [&ls](int i1, int i2){
        line l1 = ls[i1], l2 = ls[i2];
        bool flip = l1.p.x > l2.p.x;
        if (flip) swap(l1, l2);
        NUMBER cp = l1.direction() ^ (l2.p - l1.p), cq = l1.direction() ^ (l2.q - l1.p);
        return ((cp == 0 ? cq > 0 : cp > 0) ^ flip) && i1 != i2;
    };
    set<int, decltype(comp)> bst(comp);
    LinkedList<int> ll;
    vector<int> llId(n, -1);

    for (pair<int, int> p : ps){
        switch (p.second){
        case 0:
            bst.erase(bst.find(p.first));
            break;
        case 2:
            bst.insert(p.first);
        case 1:
            auto it = bst.upper_bound(p.first);
            llId[p.first] = it == bst.end() ? ll.append(p.first) : ll.insertBefore(llId[*it], p.first);
        }
    }

    vector<int> sorted(n);
    for (int i = 0, j = ll.getFirst(); j != 0; i++, j = ll.next[j])
        sorted[i] = ll.values[j];
    return sorted;
}
