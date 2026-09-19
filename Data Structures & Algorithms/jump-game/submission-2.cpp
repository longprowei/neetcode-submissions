class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = nums[i] + i; j > 0; j--) {
                if (j >= n - 1 || dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
