class Solution {
private:
    int m, n;
    void applyZeroRow(int row, vector<vector<int>>& matrix) {
        for (int j = 0; j < n; j++) {
            matrix[row][j] = 0;
        }
    }

    void applyZeroColumn(int col, vector<vector<int>>& matrix) {
        for (int i = 0; i < m; i++) {
            matrix[i][col] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        unordered_set<int> zeroRows;
        unordered_set<int> zeroColumns;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroColumns.insert(j);
                }
            }
        }

        for (int r : zeroRows) {
            applyZeroRow(r, matrix);
        }

        for (int c : zeroColumns) {
            applyZeroColumn(c, matrix);
        }
    }
};
