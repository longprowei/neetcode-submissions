class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    int ROWS, COLS;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            word[i] != board[r][c] || board[r][c] == '#') {
            return false;
        }

        board[r][c] = '#'; // to check if used this cell already
        bool res = dfs(board, word, r - 1, c, i + 1) ||
                    dfs(board, word, r + 1, c, i + 1) ||
                    dfs(board, word, r, c - 1, i + 1) ||
                    dfs(board, word, r, c + 1, i + 1);
        board[r][c] = word[i];
        return res;
    }
};
