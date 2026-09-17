class Solution {
public:
    int numDecodings(string s) {
        int dp2 = 1; // same as dp[i - 2]
        int dp1 = s[0] != '0'; // same as dp[i - 1]
        int dp = dp1;
        for (int i = 2; i <= s.size(); i++) {
            dp = 0;
            if (s[i - 1] != '0') {
                dp = dp1;
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
                dp += dp2;
            }
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};
