
#define printid [](auto x){cout << x;}
template <class InputIt, class F>
ostream& printEval(InputIt first, InputIt last, F f){
    cout << "{";
    if (first != last) f(*first++);
    while (first != last) {cout << " "; f(*first++);}
    return cout << "}";
}
template <class C, class F>
ostream& printEval(C c, F f){
    return printEval(begin(c), end(c), f);
}

template <class T>
basic_ostream<T>& operator<< (basic_ostream<T>& str, point p) {return str << "(" << p.x << " " << p.y << ")";}
template <class T, class P1, class P2>
basic_ostream<T>& operator<< (basic_ostream<T>& str, pair<P1, P2> p) {return str << "{" << p.first << " " << p.second << "}";}
template <class T, class V>
basic_ostream<T>& operator<< (basic_ostream<T>& str, vector<V> v) {return printEval(v, printid);}
template <class T, class K, class V>
basic_ostream<T>& operator<< (basic_ostream<T>& str, unordered_map<K, V> m) {return printEval(m, printid);}
