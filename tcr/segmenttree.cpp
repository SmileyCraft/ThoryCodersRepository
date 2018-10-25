
template <class T, class Combine>
struct SegmentTree{
    int n;
    vector<T> combs;
    T id;
    Combine combine;

    SegmentTree (vector<T>& values, T id, Combine combine) : n(values.size()), combs(2*values.size()), id(id), combine(combine){ // O(n)
        for (int i = 0; i < n; i++) combs[n + i] = values[i];
        for (int i = n - 1; i > 0; i--) combs[i] = combine(combs[i << 1], combs[(i << 1) | 1]);
    }

    void update(int i, T val){ // O(log n)
        for (combs[i + n] = val, i = (i + n) >> 1; i > 0; i >>= 1)
            combs[i] = combine(combs[i << 1], combs[(i << 1) + 1]);
    }

    int query(int from, int to){ // O(log n)
        T left = T(id), right = T(id);
        for (from += n, to += n; from < to; from >>= 1, to >>= 1){
            if (from & 1) left = combine(left, combs[from++]);
            if (!(to & 1)) right = combine(combs[to--], right);
        }
        return combine(from == to ? combine(left, combs[from]) : left, right);
    }
};

// TESTING

void testSegmentTree(){
    cout << "SEGMENT TREE" << endl;
    vector<int> vec = {1,2,4,0,5};
    auto sum = [](int x, int y){return x + y;};
    SegmentTree<int, decltype(sum)> st(vec, 0, sum);
    cout << st.combs << endl; // {0 12 6 6 5 1 2 4 0 5}
    cout << st.query(0, 3) << endl; // 7
    cout << st.query(1, 2) << endl; // 6
    cout << st.query(0, 4) << endl; // 12
    cout << st.query(3, 3) << endl; // 0
    st.update(3, 3);
    cout << st.query(0, 3) << endl; // 10
    auto maxi = [](int x, int y){return max(x, y);};
    SegmentTree<int, decltype(maxi)> st2(vec, 0, maxi);
    cout << st2.combs << endl; // {0 5 5 4 5 1 2 4 0 5}
    st2.update(4, 3);
    cout << st2.combs << endl; // {0 4 3 4 3 1 2 4 0 3}
    cout << endl;
}
