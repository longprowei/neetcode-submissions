class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 0; i <= amount; i++) {
            dp[i][0] = -1;
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= coins.size(); j++) {
                if (i >= coins[j - 1]) {
                    int numOfCoins = dp[i - coins[j - 1]][j];
                    dp[i][j] = (numOfCoins == -1 ? -1 : numOfCoins + 1);
                    if (dp[i][j] != -1 && dp[i][j - 1] != -1) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    }
                    if (dp[i][j] == -1) {
                        dp[i][j] = dp[i][j - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[amount][coins.size()];
    }
};
