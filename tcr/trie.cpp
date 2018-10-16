const int ALPHABET_SIZE = 26;
inline int getValue(char c) {
    return c - 'a';
}

struct TrieNode{
    TrieNode* next[ALPHABET_SIZE];
    int amount = 0;

    TrieNode(){
        for (int i = 0; i < ALPHABET_SIZE; i++) next[i] = nullptr;
    }

    void add(string& s, int i){
        if (i >= s.size()){
            amount++;
            return;
        }
        int v = getValue(s[i]);
        if (next[v] == nullptr) next[v] = new TrieNode();
        next[v]->add(s, i + 1);
    }

    int getAmount(string& s, int i){
        if (i >= s.size()) return amount;
        int v = getValue(s[i]);
        if (next[v] == nullptr) return 0;
        return next[v]->getAmount(s, i + 1);
    }
};

void testTrie(){
    TrieNode trie;
    string s1 = "hello";
    string s2 = "hell";
    trie.add(s1, 0);
    trie.add(s1, 0);
    trie.add(s1, 0);
    trie.add(s1, 0);
    cout << trie.getAmount(s1, 0) << endl; //4
    cout << trie.getAmount(s2, 0) << endl; //0
}
