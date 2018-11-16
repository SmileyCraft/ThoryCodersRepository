
using Matrix = vector<vector<NUMBER>>; // Vector of rows

Matrix operator+(Matrix x, Matrix y){ // O(mn)
    for (int i=0; i<x.size(); i++)
        for (int j=0; j<x[i].size(); j++)
            x[i][j] += y[i][j];
    return x;
}

Matrix operator*(Matrix x, Matrix y){ // O(abc) if x = a*b, y = b*c
    Matrix z(x.size(), vector<NUMBER>(y[0].size()));
    for (int i=0; i<x.size(); i++)
        for (int j=0; j<y.size(); j++)
            for (int k=0; k<y[0].size(); k++)
                z[i][k] += x[i][j] * y[j][k];
    return z;
}

vector<NUMBER> operator*(Matrix x, vector<NUMBER> v){ // O(mn)
    vector<NUMBER> w(x.size());
    for (int i=0; i<x.size(); i++)
        for (int j=0; j<v.size(); j++)
            w[i] += x[i][j] * v[j];
    return w;
}

Matrix id(int n){ // O(n^2)
    Matrix x(n, vector<NUMBER>(n));
    for (int i=0; i<n; i++) x[i][i] = 1;
    return x;
}

Matrix inverse(Matrix x){ // O(n^3)
    int n = x.size();
    Matrix y = id(n);
    for (int i=0; i<n; i++){
        int h=i;
        while (h<n && x[h][i]==0) h++;
        if (h==n) continue;
        if (h!=i){
            swap(x[i], x[h]);
            swap(y[i], y[h]);
        }
        NUMBER inv = 1/x[i][i];
        for (int j=0; j<n; j++){
            x[i][j] *= inv;
            y[i][j] *= inv;
        }
        for (int j=0; j<n; j++){
            NUMBER nb = x[j][i];
            if (i==j || nb == 0) continue;
            for (int k=0; k<n; k++){
                x[j][k] -= x[i][k] * nb;
                y[j][k] -= y[i][k] * nb;
            }
        }
    }
    return y;
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
