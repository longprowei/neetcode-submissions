class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int currMin = 1;
        int currMax = 1;
        int res = nums[0];
        for (int i = 0; i < n; i++) {
            int temp = nums[i] * currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], temp, currMin * nums[i]});
            res = max(res, currMax);
        }
        
        return res;
    }
};
