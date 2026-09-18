class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            swap(text1, text2);
        }
        int m = text1.size();
        int n = text2.size();
        
        vector<int> currRow(n + 1, 0);
        vector<int> prevRow(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    currRow[j] = 1 + prevRow[j - 1];
                } else {
                    currRow[j] = max(prevRow[j], currRow[j - 1]);
                }
            }
            swap(currRow, prevRow);
        }
        return prevRow[n];
    }
};
