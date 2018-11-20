
#include "../maths/primes.cpp"
#include "../maths/euclid.cpp"
#include "../maths/matrix.cpp"

// PRIMES

void testPrimes(){
    cout << "PRIMES" << endl;
    printEval(fromTo(0, 30), [](int i){cout << (prime(i) ? "p" : "c");}) << endl; // {c c p p c p c p c c c p c p c c c p c p c c c p c c c c c p}
    auto primes = sieve(30);
    printEval(primes, [](bool b){cout << (b ? "p" : "c");}) << endl; // {c c p p c p c p c c c p c p c c c p c p c c c p c c c c c p}
    cout << factorize(120) << endl; // {{5 1} {3 1} {2 3}}
    cout << factorSieve(10) << endl; // {{} {} {{2 1}} {{3 1}} {{2 2}} {{5 1}} {{3 1} {2 1}} {{7 1}} {{2 3}} {{3 2}}}
    cout << eulerPhi(360) << endl; // 96
    cout << eulerPhi(1000000009) << endl; // 1000000008
    cout << endl;
}

// EUCLID

void testExtended(int a, int b){
    EuclidType et = extendedEuclid(a, b);
    bool valid = et.ca * a + et.cb * b == et.x && b % et.x == 0 && a % et.x == 0;
    cout << et.ca << " " << et.cb << " " << et.x << " " << (valid ? "SUCCESS" : "FAILURE") << endl;
}

void testEuclid(){
    cout << "EUCLID" << endl;
    cout << gcd(2 * 3 * 5 * 11 * 13 * 19, 3 * 5 * 7 * 13 * 17) << endl; // 195
    cout << endl;

    cout << "EXTENDED EUCLID" << endl;
    testExtended(2 * 3 * 5 * 11 * 13 * 19, 3 * 5 * 7 * 13 * 17); // -39 137 195 SUCCESS
    testExtended(123456789, 987654321); // -8 1 9 SUCCESS
    testExtended(1, 1); // 0 1 1 SUCCESS
    testExtended(3, 0); // 1 0 3 SUCCESS
    testExtended(0, 3); // 0 1 3 SUCCESS
    testExtended(15, 21); // 3 -2 3 SUCCESS
    testExtended(15, -21); // 3 2 3 SUCCESS
    testExtended(-15, 21); // -3 -2 3 SUCCESS
    testExtended(-15, -21); // -3 2 3 SUCCESS
    testExtended(21, 15); // -2 3 3 SUCCESS
    testExtended(21, -15); // -2 -3 3 SUCCESS
    testExtended(-21, 15); // 2 3 3 SUCCESS
    testExtended(-21, -15); // 2 -3 3 SUCCESS
    cout << endl;
}

// MATRIX

void printMatrix(Matrix a){
    for (auto i : a){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

void testMatrix(){
    cout << "MATRIX" << endl;
    printMatrix(id(5));
    Matrix a{{3, 5}, {1, 2}}, b{{0, 2}, {-2, 1}};
    printMatrix(a+b);
    printMatrix(a*b);
    printMatrix(b*a);
    Matrix c{{1, 2, -1}, {2, 4, 0}, {1, 1, 0}};
    Matrix inv = inverse(c);
    printMatrix(inv);
    printMatrix(c * inv);
    cout << determinant(a) << " ";
    cout << determinant(b) << " ";
    cout << determinant(c) << endl;
    cout << c * Vector{1, 2, 3} << endl;
    cout << inv * Vector{2, 10, -1} << endl;
    printMatrix(ldivide(c, {{2}, {10}, {3}}));
    printMatrix(ldivide(c, id(3)));
    cout << endl;
}

// COMBINED TEST

void testMaths(){
    cout << "-----o-----o----- MATHEMATICAL ALGORITHMS -----o-----o-----" << endl << endl;
    testPrimes();
    testEuclid();
    testMatrix();
}
