
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
