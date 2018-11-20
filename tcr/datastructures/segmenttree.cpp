
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
            combs[i] = combine(combs[i << 1], combs[(i << 1) | 1]);
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
