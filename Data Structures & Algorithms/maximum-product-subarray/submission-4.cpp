class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n + 1, 1);
        vector<int> suffixProduct(n + 1, 1);
        int res = nums[0];
        for (int i = 1; i <= n; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
            suffixProduct[i] = suffixProduct[i - 1] * nums[n - i];
            res = max({res, prefixProduct[i], suffixProduct[i]});
        }

        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] * nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
