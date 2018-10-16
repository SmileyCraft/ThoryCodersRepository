template <class T>
struct LinkedList{
    vector<int> next, prev;
    vector<T> values;
    stack<int> garbage;

    LinkedList() : next({0}), prev({0}), values({T()}) {}

    int insertAfter(int id, T value){
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
        //next[prev[newId] = id] = prev[next[newId] = next[id]] = newId;
        return newId;
    }

    int insertBefore(int id, T value){
        return insertAfter(prev[id], value);
    }

    int append(T value){
        return insertAfter(prev[0], value);
    }

    int prepend(T value){
        return insertAfter(0, value);
    }

    void deleteId(int id){
        next[prev[id]] = next[id];
        prev[next[id]] = prev[id];
        //next[prev[next[id]] = prev[id]] = next[id];
        garbage.push(id);
    }

    int getFirst(){
        return next[0];
    }

    int getLast(){
        return prev[0];
    }
};

template <class T>
struct LinkedListIterator
{
    LinkedList<T>* ll;
    int i;

    LinkedListIterator(LinkedList<T>* ll, int i) : ll(ll), i(i) {}
    LinkedListIterator() {}

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
    unordered_map<char,int> ids;
    LinkedList<char> ll;
    for (char c = 'a'; c < 'h'; c++)
        ids[c] = ll.append(c);
    cout << ll.values[ll.next[ids['d']]] << ' '; //e
    ll.deleteId(ids['d']);
    ll.deleteId(ids['f']);
    cout << ll.values[ll.next[ll.next[ids['c']]]] << ' '; //g
    ids['d'] = ll.prepend('d');
    cout << ids['d'] << ' '; //6
    cout << ll.values[ll.prev[ids['a']]] << ' '; //d
    ids['f'] = ll.insertBefore(ids['e'], 'f');
    cout << ll.values[ll.next[ids['c']]] << ' '; //f
    ids['h'] = ll.append('h');
    cout << ids['h'] << endl; //8
    printEval(ll, identity); //{d a b c f e g h}
    printEval(++(ll.values.begin()), ll.values.end(), identity); //{ a b c f e d g h }
}
