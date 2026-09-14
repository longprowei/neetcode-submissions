class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool finish;
};

class PrefixTree {
private:
    const int ALPHABET_SIZE = 26;
    TrieNode *trie;
public:
    PrefixTree() {
        trie = new TrieNode();
        trie->finish = false;
    }
    
    void insert(string word) {
        TrieNode *curr = trie;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->finish = true;
    }
    
    bool search(string word) {
        TrieNode *curr = trie;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->finish;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = trie;
        for (auto c : prefix) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
