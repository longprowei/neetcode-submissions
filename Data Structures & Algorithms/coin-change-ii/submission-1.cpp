class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));

        for (int i = 0; i <= coins.size(); i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i <= amount; i++) {
            for (int j = 1; j <= coins.size(); j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j - 1]) {
                    dp[i][j] += dp[i - coins[j - 1]][j];
                }
                //cerr << "dp " << i << "," << j << " = " << dp[i][j] << endl;
            }
        }

        return dp[amount][coins.size()];
    }
};
