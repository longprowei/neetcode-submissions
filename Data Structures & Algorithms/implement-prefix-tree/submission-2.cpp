class PrefixTree {
private:
    const int ALPHABET_SIZE = 26;
    bool finish;
    vector<PrefixTree*> children;
public:
    PrefixTree() {
        children.resize(ALPHABET_SIZE);
        finish = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        //cerr << "insert " << word << endl;
        if (word.size() == 0) {
            finish = true;
        } else {
            if (children[word[0] - 'a'] == nullptr) {
                children[word[0] - 'a'] = new PrefixTree();
            }
            children[word[0] - 'a']->insert(word.substr(1, word.size() - 1));
        }
    }
    
    bool search(string word) {
        if (word.size() == 0) {
            return finish;
        }

        if (children[word[0] - 'a'] != nullptr) {
            return children[word[0] - 'a']->search(word.substr(1, word.size() - 1));
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        if (prefix.size() == 0) {
            return true;
        }

        if (children[prefix[0] - 'a'] != nullptr) {
            return children[prefix[0] - 'a']->startsWith(prefix.substr(1, prefix.size() - 1));
        } else {
            return false;
        }
    }
};
