
int gcd(int a, int b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

// TESTING

void testEuclid(){
    cout << "EUCLID" << endl;
    cout << gcd(2 * 3 * 5 * 11 * 13 * 19, 3 * 5 * 7 * 13 * 17) << endl; // 195
    cout << endl;
}
