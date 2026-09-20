class Solution {
private:
    // debug function
    void printMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //printMatrix(matrix);
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int temp1 = matrix[j][n - 1 - i];
                //cerr << "map " << i << "," << j << " to " << j << "," << n - 1 - i << endl;
                matrix[j][n - 1 - i] = matrix[i][j];
                int temp2 = matrix[n - 1 - i][n - 1 - j];
                //cerr << "map " << j << "," << n - 1 - i << " to " << n - 1 - i << "," << n - 1 - j << endl;
                matrix[n - 1 - i][n - 1 - j] = temp1;
                int temp3 = matrix[n - 1 - j][i];
                //cerr << "map " << n - 1 - i << "," << n - 1 - j << " to " << n - 1 - j << "," << i << endl;
                matrix[n - 1 - j][i] = temp2;
                //cerr << "map " << n - 1 - j << "," << i << " to " << i << "," << j << endl;
                matrix[i][j] = temp3;
            }
        }
        //printMatrix(matrix);
    }
};
