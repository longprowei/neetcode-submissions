class Solution {
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string>& curr, int n) {
        //check same column
        for (int i = 0; i < row; i++) {
            if (curr[i][col] == 'Q') {
                return false;
            }

            int dist = row - i;
            if (col - dist >= 0 && curr[i][col - dist] == 'Q') {
                return false;
            }

            if (col + dist < n && curr[i][col + dist] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backTracking(int n, int row, vector<string>& curr) {
        if (row >= n) {
            res.push_back(curr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, curr, n)) {
                string newRow(n, '.');
                newRow[col] = 'Q';
                curr.push_back(newRow);
                backTracking(n, row + 1, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        backTracking(n, 0, curr);
        return res;
    }
};
