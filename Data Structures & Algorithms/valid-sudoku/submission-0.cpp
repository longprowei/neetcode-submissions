class Solution {
private:
    bool isValid(unordered_set<char>& numSet, char ch) {
        if (ch != '.') {
            if (numSet.contains(ch)) {
                return false;
            }
            numSet.insert(ch);
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
    
        // check rows
        for (int i = 0; i < n; i++) {
            unordered_set<char> numSet;
            for (int j = 0; j < n; j++) {
                if (!isValid(numSet, board[i][j])) {
                    return false;
                }
            }
        }

        // check columns
        for (int j = 0; j < n; j++) {
            unordered_set<char> numSet;
            for (int i = 0; i < n; i++) {
                if (!isValid(numSet, board[i][j])) {
                    return false;
                }
            }
        }

        // check 3 x 3 squares
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                unordered_set<char> numSet;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (!isValid(numSet, board[i + k][j + l])) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
