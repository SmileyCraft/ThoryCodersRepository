
//#define LOG

#include <bits/stdc++.h>
using namespace std;

using NUMBER = long double;

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
    vector<int> v(to - from);
    for (int i = 0; i + from < to; i++) v[i] = i + from;
    return v;
}

/*int main(){
    cout << "Hello, World!" << endl;
    return 0;
}*/
