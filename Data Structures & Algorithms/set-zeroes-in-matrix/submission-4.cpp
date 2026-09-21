class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zeroRows;
        unordered_set<int> zeroColumns;

        bool lastRowZero = false;
        for (int i = 0; i < m; i++) {
            int currRowZero = false;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (!currRowZero) {
                        // set all number to 0 before j columns
                        for (int k = 0; k < j; k++) {
                            matrix[i][k] = 0;
                        }
                    }
                    // set all numbers to 0 before i rows
                    for (int k = 0; k < i; k++) {
                        matrix[k][j] = 0;
                    }
                    currRowZero = true;
                    matrix[i][j] = (i == m - 1) ? 0 : -1;
                } else {
                    if (currRowZero) {
                        matrix[i][j] = 0;
                    }
                }

                if (j == n - 1) {
                    for (int k = 0; k < n; k++) {
                        // set -1 to the 0 coloumn
                        if (lastRowZero && matrix[i - 1][k] == -1) {
                            matrix[i - 1][k] = 0;
                            matrix[i][k] = (i == m - 1) ? 0 : -1;
                        }
                    }
                }
                
            }
            if (currRowZero) {
                lastRowZero = true;
            }
        }
    }
};
