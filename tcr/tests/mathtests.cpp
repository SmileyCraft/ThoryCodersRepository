
#include "../maths/primes.cpp"
#include "../maths/euclid.cpp"

// PRIMES

void testPrimes(){
    cout << "PRIMES" << endl;
    printEval(fromTo(0, 30), [](int i){cout << (prime(i) ? "p" : "c");}) << endl; // {c c p p c p c p c c c p c p c c c p c p c c c p c c c c c p}
    auto primes = sieve(30);
    printEval(primes, [](bool b){cout << (b ? "p" : "c");}) << endl; // {c c p p c p c p c c c p c p c c c p c p c c c p c c c c c p}
    cout << factorize(120) << endl; // {{5 1} {3 1} {2 3}}
    cout << factorSieve(10) << endl; // {{} {} {{2 1}} {{3 1}} {{2 2}} {{5 1}} {{3 1} {2 1}} {{7 1}} {{2 3}} {{3 2}}}
    cout << endl;
}

// EUCLID

void testExtended(int a, int b){
    EuclidType et = extendedEuclid(a, b);
    bool valid = et.ca * a + et.cb * b == et.x && b % et.x == 0 && a % et.x == 0;
    cout << et.ca << " " << et.cb << " " << et.x << " " << (valid ? "" : "YOU ARE A FAILURE") << endl;
}

void testEuclid(){
    cout << "EUCLID" << endl;
    cout << gcd(2 * 3 * 5 * 11 * 13 * 19, 3 * 5 * 7 * 13 * 17) << endl; // 195
    cout << endl;

    cout << "EXTENDED EUCLID" << endl;
    testExtended(2 * 3 * 5 * 11 * 13 * 19, 3 * 5 * 7 * 13 * 17);
    testExtended(123456789, 987654321);
    testExtended(1, 1);
    testExtended(3, 0);
    testExtended(0, 3);
    testExtended(15, 21);
    testExtended(15, -21);
    testExtended(-15, 21);
    testExtended(-15, -21);
    testExtended(21, 15);
    testExtended(21, -15);
    testExtended(-21, 15);
    testExtended(-21, -15);
}

// COMBINED TEST

void testMaths(){
    cout << "-----o-----o----- MATHEMATICAL ALGORITHMS -----o-----o-----" << endl << endl;
    testPrimes();
    testEuclid();
}
