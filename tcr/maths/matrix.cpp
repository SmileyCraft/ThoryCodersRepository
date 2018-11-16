
using Vector = vector<NUMBER>;
using Matrix = vector<vector<NUMBER>>; // Vector of rows

Matrix toMat(Vector v){
    Matrix x(v.size());
    for (int i=0;i<v.size();i++) x[i] = {v[i]};
    return x;
}

Vector toVec(Matrix x){
    Vector v(x.size());
    for (int i=0;i<v.size();i++) v[i] = x[i][0];
    return v;
}

template <class T>
vector<T> operator+=(vector<T> &x, vector<T> y){ // O(n)
    for (int i=0; i<x.size(); i++) x[i] += y[i];
    return x;
}

template <class T>
vector<T> operator*=(vector<T> &x, NUMBER y){ // O(n)
    for (int i=0; i<x.size(); i++) x[i] *= y;
    return x;
}

template <class T> vector<T> operator+(vector<T> x, vector<T> y){ return x+=y;}
template <class T> vector<T> operator*(vector<T> x, NUMBER y)   { return x*=y;}

Matrix operator*(Matrix x, Matrix y){ // O(abc) if x = a*b, y = b*c
    Matrix z(x.size(), Vector(y[0].size()));
    for (int i=0; i<x.size(); i++)
        for (int j=0; j<y.size(); j++)
            for (int k=0; k<y[0].size(); k++)
                z[i][k] += x[i][j] * y[j][k];
    return z;
}

Vector operator*(Matrix x, Vector v){ // O(mn)
    return toVec(x * toMat(v));
}

Matrix id(int n){ // O(n^2)
    Matrix x(n, Vector(n));
    for (int i=0; i<n; i++) x[i][i] = 1;
    return x;
}

Matrix ldivide(Matrix x, Matrix y){ // O(n^3), returns a such that xa = y
    int n = x.size();
    for (int i=0; i<x[0].size(); i++){
        int h=i;
        while (h<n && x[h][i]==0) h++;
        if (h==n) { // Not invertible: multiple solutions. When only inverting matrices, replace this block by: return {};
            x.push_back(Vector(x[0].size()));
            y.push_back(Vector(y[0].size()));
            x[n][i] = 1;
            n++;
        };
        if (h!=i){
            swap(x[i], x[h]);
            swap(y[i], y[h]);
        }
        NUMBER inv = 1/x[i][i];
        x[i] *= inv;
        y[i] *= inv;
        for (int j=0; j<n; j++){
            NUMBER nb = -x[j][i];
            if (i==j || nb == 0) continue;
            x[j] += x[i] * nb;
            y[j] += y[i] * nb;
        }
    }
    for (;y.size()>n;y.pop_back()){ // When only inverting matrices, this loop can be removed.
        for (int j=0; j<y[0].size(); j++)
            if (y[n][j] != 0)
                return {}; // Inconsistent solution
    }
    return y;
}

Matrix inverse(Matrix x){ // O(n^3)
    return ldivide(x, id(x.size()));
}

Vector solve(Matrix x, Vector v){ // O(n^3), finds w such that xw == v
    return toVec(ldivide(x, toMat(v)));
}

NUMBER determinant(Matrix x){ // O(n^3)
    int n = x.size();
    NUMBER det = 1;
    for (int i=0; i<n; i++){
        int h=i;
        while (h<n && x[h][i]==0) h++;
        if (h==n) return 0;
        if (h!=i){
            swap(x[i], x[h]);
            det *= -1;
        }
        det *= x[i][i];
        NUMBER inv = 1/x[i][i];
        for (int j=i+1; j<n; j++){
            NUMBER nb = x[j][i] * inv;
            for (int k=i; k<n; k++)
                x[j][k] -= x[i][k] * nb;
        }
    }
    return det;
}
