
const int TRIE_ALPHABET_SIZE = 26;
inline int trieValue(char c) {return c - 'a';}
struct TrieNode{
    vector<TrieNode*> next;
    int amount = 0;

    TrieNode() : next(TRIE_ALPHABET_SIZE, nullptr) {} // O(1)

    void add(string& s, int i){ // O(|s|)
        if (i >= s.size()){
            amount++;
            return;
        }
        int v = trieValue(s[i]);
        if (next[v] == nullptr) next[v] = new TrieNode();
        next[v]->add(s, i + 1);
    }

    int getAmount(string& s, int i){ // O(|s|)
        if (i >= s.size()) return amount;
        int v = trieValue(s[i]);
        if (next[v] == nullptr) return 0;
        return next[v]->getAmount(s, i + 1);
    }
};

// TESTING

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
