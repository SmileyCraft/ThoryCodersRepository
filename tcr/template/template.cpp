
#include <bits/stdc++.h>
using namespace std;

vector<int> fromTo(int from, int to){
    vector<int> v(to - from);
    for (int i = 0; i + from < to; i++) v[i] = i + from;
    return v;
}

/*int main(){
    cout << "Hello, World!" << endl;
    return 0;
}*/
