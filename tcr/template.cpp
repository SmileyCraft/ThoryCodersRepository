
//#define LOG

#include <bits/stdc++.h>
using namespace std;

template <class T>
void Log(T t){
    #ifdef LOG
    cout << t;
    #endif
}
template <class T1, class T2, class... S>
void Log(T1 t1, T2 t2, S... s){
    Log(t1);
    Log(t2, s...);
}
template <class T, class... S>
void LogLn(T t, S... s){
    Log(t, s..., "\n");
}

vector<int> fromTo(int from, int to){
    vector<int> v;
    for (int i = from; i < to; i++) v.push_back(i);
    return v;
}

#define identity [](auto x){return x;}
#define tostring [](auto x){return to_string(x);}
template <class InputIt, class F>
string evalString(InputIt first, InputIt last, F f){
    string s = "{";
    string* p = &s;
    if (first != last) s += f(*first++);
    for_each(first, last, [f, p](auto &x)mutable{*p += " "; *p += f(x);});
    s += "}";
    return s;
}
template <class T, class F>
string evalString(T t, F f){
    return evalString(begin(t), end(t), f);
}
template<class InputIt, class F>
void printEval(InputIt first, InputIt last, F f){
    cout << evalString(first, last, f) << endl;
}
template<class T, class F>
void printEval(T t, F f){
    cout << evalString(t, f) << endl;
}
