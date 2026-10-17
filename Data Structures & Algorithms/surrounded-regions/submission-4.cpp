class Solution {
private:
    int ROWS, COLS;
    static constexpr pair<int,int> DELTA[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'N';
        
        for (auto [dr, dc] : DELTA) {
            int nr = dr + r;
            int nc = dc + c;
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && board[nr][nc] == 'O') {
                dfs(board, nr, nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        // first row and last row;
        for (int j = 0; j < COLS; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }

            if (board[ROWS - 1][j] == 'O') {
                dfs(board, ROWS - 1, j);
            }
        }

        // first column and last column
        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][COLS - 1] == 'O') {
                dfs(board, i, COLS - 1);
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
