class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned> dp(amount + 1);
        dp[0] = 1;
        for (const auto & coin : coins) {
            for (int i = 1; i <= amount; i++) {
                dp[i] = dp[i];
                if (i >= coin) {
                    dp[i] += dp[i - coin];
                }
            }
        }

        return dp[amount];
    }
};
