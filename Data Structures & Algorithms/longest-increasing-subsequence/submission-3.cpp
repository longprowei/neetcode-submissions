class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp; // dp[i] is smallest tail value for the sequence length i + 1
        for (auto num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }
};
