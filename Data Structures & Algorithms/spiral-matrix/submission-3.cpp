class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        int l = 0, r = n - 1;
        int top = 0, bottom = m - 1;
        while (l <= r && top <= bottom) {
            // top row
            for (int j = l; j <= r; j++) {
                res.push_back(matrix[top][j]);
            }

            // right column
            for (int i = top + 1; i < bottom; i++) {
                res.push_back(matrix[i][r]);
            }

            // bottom row;
            if (bottom - top >= 1) {
                for (int j = r; j >= l; j--) {
                    res.push_back(matrix[bottom][j]);
                }
            }
            
            // left column
            if (r - l >= 1) {
                for (int i = bottom - 1; i >= 0 && i > top; i--) {
                    res.push_back(matrix[i][l]);
                }
            }
            l++;
            r--;
            top++;
            bottom--;
        }
        return res;
    }
};
