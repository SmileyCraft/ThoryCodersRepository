
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

// TESTING

void printUnionFind(UnionFind uf){
    printEval(fromTo(0, uf.parents.size()), [uf](int i)mutable{cout << uf.groupId(i);}) << endl;
}

void testUnionFind(){
    cout << "UNION FIND" << endl;
    UnionFind uf(6);
    uf.combine(0, 1);
    uf.combine(2, 3);
    printUnionFind(uf); // {0 0 2 2 4 5}
    UnionFind uf2 = uf;
    uf2.combine(0, 3);
    printUnionFind(uf2); // {0 0 0 0 4 5}
    uf.combine(3, 0);
    printUnionFind(uf); // {2 2 2 2 4 5}
    cout << uf.groupSize(0) << endl; // 4
    uf.combine(1, 4);
    uf.combine(5, 3);
    printUnionFind(uf); // {2 2 2 2 2 2}
    cout << endl;
}
