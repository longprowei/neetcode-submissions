class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;

        dp[0] = 1; // if sum is 0, there is 1 way
        for (const auto & num : nums) {
            unordered_map<int, int> newDp;
            for (const auto & [total, ways] : dp) {
                newDp[total + num] += ways;
                newDp[total - num] += ways;
            }
            dp = newDp;
        }

        return dp[target];
    }
};
