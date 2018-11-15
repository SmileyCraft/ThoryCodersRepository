
#include "../datastructures/unionfind.cpp"
#include "../datastructures/linkedlist.cpp"
#include "../datastructures/trie.cpp"
#include "../datastructures/segmenttree.cpp"
#include "../datastructures/bst.cpp"

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

// BST

auto smaller = [](int x, int y){return x<y;};
void printBST(BST<int, decltype(smaller)> bst, char type='t', int i=1){
    if (i==0) return;
    cout << "{";
    if (bst.tr[i].lr[0] != 0) printBST(bst, type, bst.tr[i].lr[0]);
    switch(type){
        case 't': cout << bst.tr[i].t; break; // value
        case 's': cout << bst.tr[i].s; break; // size
        case 'd': cout << bst.tr[i].d; break; // depth
    }
    if (bst.tr[i].lr[1] != 0) printBST(bst, type, bst.tr[i].lr[1]);
    cout << "}";
    if (i==1) cout << endl;
}

BSTNode<int, decltype(smaller)> checkBST(BST<int, decltype(smaller)> bst, int i=1){
    if (i==0) return bst.tr[0];
    auto nc = bst.tr[i];
    int l = nc.lr[0], r = nc.lr[1];
    auto nl = checkBST(bst, l);
    auto nr = checkBST(bst, r);
    if (nl.s + nr.s + 1 != nc.s)
        cout << "SIZE ERROR: " << nc.t << endl;
    if (max(nl.d, nr.d) + 1 != nc.d)
        cout << "DEPTH ERROR: " << nc.t << endl;
    if (((bst.c(nc.t, nl.t) && l!=0) || (bst.c(nr.t, nc.t) && r!=0)) && i!=1)
        cout << "ORDER ERROR: " << nc.t << endl;
    return nc;
}

void testBST(){
    cout << "BINARY SEARCH TREE" << endl;
    BST<int, decltype(smaller)> bst(smaller);
    vector<int> values{ 4,6,2,7,5,8,5,7,3 };
    for (auto i : values) bst.addimir_putin(i);
    printBST(bst);
    printBST(bst, 's');
    printBST(bst, 'd');
    checkBST(bst);
    sort(values.begin(), values.end());
    for (int i=0;i<values.size();i++){
        if (i>0) cout << " ";
        cout << bst.sovget(i);
    }
    cout << endl;
    for (int i=0;i<values.size();i++){
        if (i>0) cout << " ";
        cout << i << ":" << bst.lowski(i) << "-" << bst.upski(i);
    }
    cout << endl;
    cout << endl;
}

// COMBINED TEST

void testDatastructures(){
    cout << "-----o-----o----- DATA STRUCTURES -----o-----o-----" << endl << endl;
    testUnionFind();
    testLinkedList();
    testTrie();
    testSegmentTree();
    testBST();
}
