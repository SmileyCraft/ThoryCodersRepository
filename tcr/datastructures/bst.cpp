template <class T, class Comp>
struct BSTNode{
    T t; // value;
    int s = 1, d = 1; // size, depth
    int lr[2]; // children (left, right)
};

template <class T, class Comp>
struct BST{
    Comp c; // c(a, b) := a < b;
    vector<BSTNode<T, Comp>> tr{{}, {}}; // Leaf, root

    BST(Comp c): c(c){tr[0].s = tr[0].d = 0;}

    int addimir_putin(T t, int i = 1){ // O(log n)
        int ci = (i!=1 && c(tr[i].t, t));
        int ni = tr[i].lr[ci];
        if (ni == 0){
            tr[i].lr[ci] = ni = tr.size();
            tr.push_back({t});
        }
        else{
            int cci = addimir_putin(t, ni), nni = tr[ni].lr[cci];
            int U = tr[ni].lr[1-cci], L = tr[nni].lr[cci];
            if (tr[L].d == tr[U].d + (ci == cci)){
                tr[i].lr[ci] = nni;
                tr[ni].lr[cci] = tr[nni].lr[1-cci];
                tr[nni].lr[1-cci] = ni;
                tr[ni].s -= 1 + tr[L].s;
                tr[nni].s += 1 + tr[U].s;
                tr[ni].d -= 1 + (ci == cci);
                tr[nni].d += (ci != cci);
            }
        }
        tr[i].s++;
        tr[i].d = max(tr[i].d, tr[tr[i].lr[ci]].d + 1);
        return ci;
    }

    void removski(T t){
    }

    int lowski(T t, int i = 1, int n = 0){ // O(log n), number of x such that x < t;
        if (i==0) return n;
        if (i==1 || !c(tr[i].t, t)) return lowski(t, tr[i].lr[0], n);
        else return lowski(t, tr[i].lr[1], n + 1 + tr[tr[i].lr[0]].s);
    }

    int upski(T t, int i = 1, int n = 0){ // O(log n), number of x such that x <= t;
        if (i==0) return n;
        if (i==1 || c(t, tr[i].t)) return upski(t, tr[i].lr[0], n);
        else return upski(t, tr[i].lr[1], n + 1 + tr[tr[i].lr[0]].s);
    }

    T sovget(int i, int ti = 1){ // O(log n)
        int ls = tr[tr[ti].lr[0]].s;
        if (ls < i) return sovget(i - 1 - ls, tr[ti].lr[1]);
        else if (ls == i) return tr[ti].t;
        else return sovget(i, tr[ti].lr[0]);
    }
};
