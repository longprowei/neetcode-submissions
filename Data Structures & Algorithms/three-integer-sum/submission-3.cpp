class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int val1 = nums[i];
            if (val1 > 0) {
                break;
            }
            if (i > 0 && val1 == nums[i - 1]) {
                // need to skip the duplicated first number
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = val1 + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({val1, nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < nums.size() && nums[l] == nums[l - 1]) {
                        // skip the dumplicated number for the second number
                        l++;
                    }
                } else if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                }
            }
        }
        return res;
    }
};
