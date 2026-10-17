class Solution {
private:
    int ROWS, COLS;
    static constexpr pair<int,int> DELTA[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& board, int r, int c) {
        visited[r][c] = true;
        board[r][c] = 'N';
        
        for (auto [dr, dc] : DELTA) {
            int nr = dr + r;
            int nc = dc + c;
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && board[nr][nc] == 'O' && !visited[nr][nc]) {
                dfs(board, nr, nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        // first row and last row;
        for (int j = 0; j < COLS; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, 0, j);
            }

            if (board[ROWS - 1][j] == 'O' && !visited[ROWS - 1][j]) {
                dfs(board, ROWS - 1, j);
            }
        }

        // first column and last column
        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, i, 0);
            }

            if (board[i][COLS - 1] == 'O' && !visited[i][COLS - 1]) {
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
