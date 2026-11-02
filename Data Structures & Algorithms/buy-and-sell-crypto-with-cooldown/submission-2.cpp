class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0)); // j is 0, buy, j is 1 sell, j is 2 for do nothing
        for (int i = 1; i < n; i++) {
            if (i > 1) {
                dp[i][0] = dp[i - 2][1];
            }
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);
            int maxProfit = INT_MIN;
            for (int j = 0; j < i; j++) {
                maxProfit = max(maxProfit, prices[i] - prices[j] + dp[j][0]);
            }
            dp[i][1] = maxProfit;
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ret = max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};
