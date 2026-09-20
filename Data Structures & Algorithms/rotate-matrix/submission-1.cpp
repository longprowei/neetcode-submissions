class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //reverse all rows
        reverse(matrix.begin(), matrix.end());

        // then switch row and column will become rotate 90 degree clockwise
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
