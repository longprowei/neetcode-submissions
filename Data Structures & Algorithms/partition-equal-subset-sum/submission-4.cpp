class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % 2 != 0) {
            return false;
        }
        
        int n = nums.size();
        int halfSum = numSum / 2;
        // dp[i][j] means select elements(0 to i + 1 elements) up to element i, if sum j is possible
        vector<vector<bool>> dp(n, vector<bool>(halfSum + 1));
        for (int j = 0; j <= halfSum; j++) {
            dp[0][j] = false;    
        }

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
            if (nums[i] <= halfSum) {
                dp[i][nums[i]] = true;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= halfSum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i] >= 0) {
                     dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[n - 1][halfSum];
    }
};
