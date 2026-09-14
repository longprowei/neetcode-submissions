class TrieNode {
private:
    const int ALPHABET_SIZE = 26;
public:
    unordered_map<char, TrieNode*> children;
    bool finish;
    TrieNode() {
        finish = false;
    }
    
    void insert(string word) {
        TrieNode *curr = this;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->finish = true;
    }
};

class Solution {
private:
    int ROWS, COLS;
    unordered_set<string> res;
    static constexpr pair<int, int> DELTAS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfsFind(vector<vector<char>>& board, TrieNode* node, int r, int c, string currWord) {
        char currChar = board[r][c];
        if (!node->children.contains(currChar) || currChar == '#') {
            return;
        }

        currWord += currChar;
        node = node->children[board[r][c]];
        if (node->finish) {
            res.insert(currWord);
        }

        board[r][c] = '#';
        for (auto [dr, dc] : DELTAS) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS) {
                dfsFind(board, node, nr, nc, currWord);
            }
        }
        board[r][c] = currChar;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for (auto word : words) {
            trie->insert(word);
        }

        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                dfsFind(board, trie, i, j, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
