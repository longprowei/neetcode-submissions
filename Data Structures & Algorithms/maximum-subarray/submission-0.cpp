class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (currSum <= 0) {
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
            res = max(res, currSum);
        }
        return res;
    }
};
