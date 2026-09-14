class WordDictionary {
private:
    unordered_map<char, WordDictionary*> children;
    bool finish;
public:
    WordDictionary() {
        finish = false;
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new WordDictionary();
            }
            curr = curr->children[c];
        }
        curr->finish = true;
    }
    
    bool search(string word) {
        if (word.size() == 0) {
            return finish;
        }

        char ch = word[0];
        string suffix = word.substr(1, word.size() - 1);
        if (ch == '.') {
            bool match = false;
            for (auto [c, dict] : children) {
                if (dict->search(suffix)) {
                    match = true;
                    break;
                }
            }
            return match;
        } else {
            if (!children.contains(ch)) {
                return false;
            }
            return children[ch]->search(suffix);
        }
    }
};
