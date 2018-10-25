
#include "../datastructures/unionfind.cpp"
#include "../datastructures/linkedlist.cpp"
#include "../datastructures/trie.cpp"
#include "../datastructures/segmenttree.cpp"

// UNION FIND

void printUnionFind(UnionFind uf){
    printEval(fromTo(0, uf.parents.size()), [uf](int i)mutable{cout << uf.groupId(i);}) << endl;
}

void testUnionFind(){
    cout << "UNION FIND" << endl;
    UnionFind uf(6);
    uf.combine(0, 1);
    uf.combine(2, 3);
    printUnionFind(uf); // {0 0 2 2 4 5}
    UnionFind uf2 = uf;
    uf2.combine(0, 3);
    printUnionFind(uf2); // {0 0 0 0 4 5}
    uf.combine(3, 0);
    printUnionFind(uf); // {2 2 2 2 4 5}
    cout << uf.groupSize(0) << endl; // 4
    uf.combine(1, 4);
    uf.combine(5, 3);
    printUnionFind(uf); // {2 2 2 2 2 2}
    cout << endl;
}

// LINKED LIST

template <class T>
struct LinkedListIterator
{
    LinkedList<T>* ll;
    int i;

    LinkedListIterator(LinkedList<T>* ll = nullptr, int i = 0) : ll(ll), i(i) {}

    T& operator*() const {return ll->values[i];}
    LinkedListIterator& operator++() {i = ll->next[i]; return *this;}
    LinkedListIterator operator++(int) {LinkedListIterator<T> retval = LinkedListIterator(ll, i); ++(*this); return retval;}
    bool operator!=(const LinkedListIterator<T>& lli) {return i != lli.i;}
};
template <class T>
LinkedListIterator<T> begin(LinkedList<T>& ll){
    return LinkedListIterator<T>(&ll, ll.getFirst());
}
template <class T>
LinkedListIterator<T> end(LinkedList<T>& ll){
    return LinkedListIterator<T>(&ll, 0);
}

void testLinkedList(){
    cout << "LINKED LIST" << endl;
    unordered_map<char,int> ids;
    LinkedList<char> ll;
    for (char c = 'a'; c < 'h'; c++)
        ids[c] = ll.append(c);
    cout << ll.values[ll.next[ids['d']]] << ' '; // e
    ll.deleteId(ids['d']);
    ll.deleteId(ids['f']);
    cout << ll.values[ll.next[ll.next[ids['c']]]] << ' '; // g
    ids['d'] = ll.prepend('d');
    cout << ids['d'] << ' '; // 6
    cout << ll.values[ll.prev[ids['a']]] << ' '; // d
    ids['f'] = ll.insertBefore(ids['e'], 'f');
    cout << ll.values[ll.next[ids['c']]] << ' '; // f
    ids['h'] = ll.append('h');
    cout << ids['h'] << endl; // 8
    printEval(ll, printid) << endl; // {d a b c f e g h}
    printEval(++(ll.values.begin()), ll.values.end(), printid) << endl; // {a b c f e d g h}
    cout << endl;
}

// TRIE

void testTrie(){
    cout << "TRIE" << endl;
    TrieNode trie;
    string s1 = "hello";
    string s2 = "hell";
    trie.add(s1, 0);
    trie.add(s1, 0);
    trie.add(s1, 0);
    trie.add(s1, 0);
    cout << trie.getAmount(s1, 0) << endl; // 4
    cout << trie.getAmount(s2, 0) << endl; // 0
    cout << endl;
}

// SEGMENT TREE

void testSegmentTree(){
    cout << "SEGMENT TREE" << endl;
    vector<int> vec = {1,2,4,0,5};
    auto sum = [](int x, int y){return x + y;};
    SegmentTree<int, decltype(sum)> st(vec, 0, sum);
    cout << st.combs << endl; // {0 12 6 6 5 1 2 4 0 5}
    cout << st.query(0, 3) << endl; // 7
    cout << st.query(1, 2) << endl; // 6
    cout << st.query(0, 4) << endl; // 12
    cout << st.query(3, 3) << endl; // 0
    st.update(3, 3);
    cout << st.query(0, 3) << endl; // 10
    auto maxi = [](int x, int y){return max(x, y);};
    SegmentTree<int, decltype(maxi)> st2(vec, 0, maxi);
    cout << st2.combs << endl; // {0 5 5 4 5 1 2 4 0 5}
    st2.update(4, 3);
    cout << st2.combs << endl; // {0 4 3 4 3 1 2 4 0 3}
    cout << endl;
}

// COMBINED TEST

void testDatastructures(){
    cout << "-----o-----o----- DATA STRUCTURES -----o-----o-----" << endl << endl;
    testUnionFind();
    testLinkedList();
    testTrie();
    testSegmentTree();
}
