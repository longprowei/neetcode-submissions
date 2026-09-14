struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool finish;
    TrieNode() : finish(false) {}
};

class WordDictionary {
private:
    TrieNode* trie;
public:
    WordDictionary() : trie (new TrieNode()) {
    }
    
    void addWord(string word) {
        TrieNode* curr = trie;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->finish = true;
    }
    
    bool search(string word) {
        return dfsSearch(word, trie);
    }
private:
    bool dfsSearch(string word, TrieNode* node) {
        if (word.size() == 0) {
            return node->finish;
        }

        char ch = word[0];
        string suffix = word.substr(1, word.size() - 1);
        if (ch == '.') {
            bool match = false;
            for (auto [c, node] : node->children) {
                if (dfsSearch(suffix, node)) {
                    match = true;
                    break;
                }
            }
            return match;
        } else {
            if (!node->children.contains(ch)) {
                return false;
            }
            return dfsSearch(suffix, node->children[ch]);
        }
    }
};
