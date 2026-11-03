class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));

        dp[0][0] = 1;
        for (int i = 0; i <= amount; i++) {
            for (int j = 1; j <= coins.size(); j++) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    if (i - coins[j - 1] >= 0) {
                        dp[i][j] = dp[i - coins[j - 1]][j] + dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
                //cerr << "dp " << i << "," << j << " = " << dp[i][j] << endl;
            }
        }

        return dp[amount][coins.size()];
    }
};
