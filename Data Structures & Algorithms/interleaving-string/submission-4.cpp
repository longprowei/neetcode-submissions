class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n) {
            return false;
        }

        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int i = m; i >= 0; i--) {
            vector<bool> nextDp(n + 1);
            if (i == m) {
                nextDp[n] = true;
            }
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j] && dp[j]) {
                    nextDp[j] = true;
                }

                if (j < n && s2[j] == s3[i + j] && nextDp[j + 1]) {
                    nextDp[j] = true;
                }
            }
            dp = nextDp;
        }

        return dp[0];
    }
};
