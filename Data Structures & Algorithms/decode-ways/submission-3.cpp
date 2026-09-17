class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if (s[0] != '0') {
            dp[0] = 1;
        }
        for (int i = 1; i < s.size(); i++) {
            int combinNum = stoi(s.substr(i - 1, 2));
            if (s[i] != '0' && s[i - 1] != '0' && combinNum <= 26) {
                if (i >= 2) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1] + 1;
                } 
            } else if (s[i] == '0' && s[i - 1] != '0' && combinNum <= 26) {
                if (i >= 2) {
                    dp[i] = dp[i - 2];
                } else {
                    dp[i] = 1;
                }
            } else if (s[i] != '0' && s[i - 1] != 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = 0;
            }
        }
        return dp[s.size() - 1];
    }
};
