class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool finish;
};

class Trie {
private:
    const int ALPHABET_SIZE = 26;
    TrieNode *trie;
public:
    Trie() {
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

class Solution {
private:
    Trie *trie;
    int ROWS, COLS;
    unordered_set<string> res;
    static constexpr pair<int, int> DELTAS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfsFind(vector<vector<char>>& board, int r, int c, string currWord) {
        char currChar = board[r][c];
        if (currChar == '#') {
            return;
        }

        currWord += currChar;
        if (!trie->startsWith(currWord)) {
            return;
        }

        if (trie->search(currWord)) {
            res.insert(currWord);
        }

        board[r][c] = '#';
        for (auto [dr, dc] : DELTAS) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS) {
                dfsFind(board, nr, nc, currWord);
            }
        }
        board[r][c] = currChar;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = new Trie();
        for (auto word : words) {
            trie->insert(word);
        }

        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                string currWord;
                dfsFind(board, i, j, currWord);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
