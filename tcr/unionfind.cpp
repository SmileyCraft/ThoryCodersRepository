struct UnionFind{
    vector<int> ps, rs;

    UnionFind(int n) : ps(n), rs(n) {
        for (int i = 0; i < n; i++) ps[i] = i;
    }

    UnionFind() : UnionFind(0) {}

    int find(int x){
        return ps[x] == x ? x : (ps[x] = find(ps[x]));
    }

    void merge(int x, int y){
        if ((x = find(x)) == (y = find(y))) return;
        if (rs[x] < rs[y]) swap(x, y);
        ps[y] = x;
        if (rs[x] == rs[y]) rs[x]++;
    }
};

void printUF(UnionFind uf){
    printEval(fromTo(0, uf.ps.size()), [uf](int i)mutable{return to_string(uf.find(i));});
}

void testUnionFind(){
    UnionFind uf(6);
    uf.merge(0, 1);
    uf.merge(2, 3);
    printUF(uf); //0 0 2 2 4 5
    UnionFind uf2 = uf;
    uf2.merge(0, 3);
    printUF(uf2); //0 0 0 0 4 5
    uf.merge(3, 0);
    printUF(uf); //2 2 2 2 4 5
    uf.merge(1, 4);
    uf.merge(5, 3);
    printUF(uf); //2 2 2 2 2 2
}
