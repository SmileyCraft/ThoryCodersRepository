
template <class T>
struct LinkedList{
    vector<int> next, prev;
    vector<T> values;
    stack<int> garbage;

    LinkedList() : next(1, 0), prev(1, 0), values(1, T()) {} // O(1)

    int insertAfter(int id, T& value){ // O(1)
        int newId = next.size();
        if (garbage.empty()){
            next.push_back(-1);
            prev.push_back(-1);
            values.push_back(value);
        }
        else{
            newId = garbage.top();
            garbage.pop();
            values[newId] = value;
        }
        next[newId] = next[id];
        prev[newId] = id;
        prev[next[id]] = newId;
        next[id] = newId;
        return newId;
    }

    int insertBefore(int id, T value) {return insertAfter(prev[id], value);} // O(1)
    int append(T value) {return insertAfter(prev[0], value);} // O(1)
    int prepend(T value) {return insertAfter(0, value);} // O(1)

    void deleteId(int id){ // O(1)
        next[prev[id]] = next[id];
        prev[next[id]] = prev[id];
        garbage.push(id);
    }

    int getFirst() {return next[0];} // O(1)
    int getLast() {return prev[0];} // O(1)
};

// TESTING

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
