class Solution {
    int colConf = 0, posDiagConf = 0, negDiagConf = 0;
    vector<vector<string>> res;

    void backTracking(int n, int row, vector<string>& board) {
        if (row >= n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (colConf & (1 << col) || posDiagConf & (1 << (row + col)) || negDiagConf & (1 << (row - col + n))) {
                continue;
            }

            board[row][col] = 'Q';
            colConf ^= (1 << col);
            posDiagConf ^= (1 << (row + col));
            negDiagConf ^= (1 << (row - col + n));
            
            backTracking(n, row + 1, board);

            //back tracking
            board[row][col] = '.';
            colConf ^= (1 << col);
            posDiagConf ^= 1 << (row + col);
            negDiagConf ^= 1 << (row - col + n);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTracking(n, 0, board);
        return res;
    }
};
