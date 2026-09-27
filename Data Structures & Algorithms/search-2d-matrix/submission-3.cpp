class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> firstNums(m);
        
        for (int i = 0; i < m; i++) {
            firstNums[i] = matrix[i][0];
        }

        auto it = lower_bound(firstNums.begin(), firstNums.end(), target);
        int targetRow = 0;
        if (it == firstNums.end()) {
            targetRow = m - 1; // last row
        } else {
            targetRow = it - firstNums.begin();
        }

        if (matrix[targetRow][0] == target) {
            return true;
        } else {
            if (targetRow > 0 && matrix[targetRow][0] > target) {
                targetRow--;
            }
            return binary_search(matrix[targetRow].begin(), matrix[targetRow].end(), target);
        }
    }
};
