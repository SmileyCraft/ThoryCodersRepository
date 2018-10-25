
struct UnionFind{
    vector<int> parents, ranks, sizes;

    UnionFind(int n = 0) : parents(fromTo(0, n)), ranks(n, 0), sizes(n, 1) {} // O(n)

    int groupId(int i) {return parents[i] == i ? i : (parents[i] = groupId(parents[i]));} // O(a(n))
    int groupSize(int i) {return sizes[groupId(i)];} // O(a(n))

    void combine(int i, int j){ // O(a(n))
        if ((i = groupId(i)) == (j = groupId(j))) return;
        if (ranks[i] < ranks[j]) swap(i, j);
        parents[j] = i;
        sizes[i] += sizes[j];
        if (ranks[i] == ranks[j]) ranks[i]++;
    }
};
