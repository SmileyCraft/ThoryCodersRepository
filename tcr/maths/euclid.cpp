
int gcd(int a, int b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct EuclidType{
    int ca;
    int cb;
    int x;

    EuclidType operator + (EuclidType param){
        return {ca + param.ca, cb + param.cb, x + param.x};
    }

    EuclidType operator * (int param){
        return {param * ca, param * cb, param * x};
    }
};

EuclidType extendedEuclid(int a, int b){
    EuclidType prev = {1, 0, a};
    EuclidType current = {0, 1, b};

    while (current.x != 0){
        EuclidType next = prev + current * (-prev.x / current.x);
        prev = current;
        current = next;
    }
    return (prev.x >= 0 ? prev : prev * -1);
}
