
string line; getline(cin, line); // Use this to read a whole line. Returns true if there was a line to read.

// Use this for custom timing.
auto start = chrono::high_resolution_clock::now();
auto finish = chrono::high_resolution_clock::now();
auto microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);

auto comp = [](T i, T j){return i < j;};
sort(v.begin(), v.end(), comp); // Sort vector v.
priority_queue<T, vector<T>, decltype(comp)> q(comp); // Max heap.
set<T, decltype(comp)> s(comp); // Balanced binary search tree.
map<T, S, decltype(comp)> m(comp); // Balanced binary search tree map with key T and value S.

random_device rd; mt19937 gen(rd());
uniform_int_distribution<ll> uid(1, 9); // Generate integers between 1 and 9 inclusive.
uniform_real_distribution<ld> urd(1.0, 2.0); // Generate real numbers between 1 and 2 left-inclusive.
ll x = uid(gen); ld y = urd(gen);

// Order statistics tree. Note that duplicate entries are ignored.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class S> // The key and value types. S can be null_type.
using order_tree = tree<T, S, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ot.find_by_order(i); // Find the i'th smallest element, zero-based.
order_of_key(v); // Find the amount of strictly smaller elements.
