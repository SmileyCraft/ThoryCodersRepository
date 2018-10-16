bool divIsPower(int n, int i){
    while (i<n)
        i <<= 1;
    return i==n;
}

bool isParent(int child, int parent){
    while (child > parent)
        child >>= 1;
    return (child == parent);
}

template <class T>
struct SegmentTree{
    vector<T> combs;
    T id;
    int n;

    T combine(T a, T b){
        return a+b;
    }

    SegmentTree (vector<T> values, T id) : n(values.size()), combs(2*values.size()), id(id){
        for (int i=0; i<n; i++)
            combs[n+i] = values[i];
        for (int i=n-1; i>0; i--)
            combs[i] = combine(combs[2*i], combs[2*i+1]);
    }

    int query(int from, int to){
        T left = T(id), right = T(id);
        for (from += n, to += n; from < to; from >>= 1, to >>= 1) {
            if (from&1 ) left = combine(left, combs[from++]);
            if (!(to&1)) right = combine(combs[to--], right);
        }
        return combine(from == to ? combine(left, combs[from]) : left, right);
    }
};

void testSegmentTree(){
    SegmentTree<int> st({1,2,4,0,5}, 0);
    printEval(st.combs, tostring);

    cout << st.query(0, 3) << endl;
    cout << st.query(1, 2) << endl;
    cout << st.query(0, 4) << endl;
    cout << st.query(3, 3) << endl;
}
