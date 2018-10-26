
int gcd(int a, int b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct EuclidType{
    int ca, cb, x;
    EuclidType operator+ (EuclidType other) {return {ca + other.ca, cb + other.cb, x + other.x};}
    EuclidType operator* (int scalar) {return {scalar * ca, scalar * cb, scalar * x};}
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
