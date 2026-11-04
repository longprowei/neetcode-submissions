class Solution {
private:
    unordered_map<string, int> mem;
    int backTracking(vector<int>& nums, int target, int i, int currSum) {
        if (i >= nums.size()) {
            return currSum == target;
        }

        string key = to_string(i) + "#" + to_string(currSum);
        if (mem.contains(key)) {
            return mem[key];
        }
        
        int ret = backTracking(nums, target, i + 1, currSum + nums[i]) + 
            backTracking(nums, target, i + 1, currSum - nums[i]);
        mem[key] = ret;

        return ret;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backTracking(nums, target, 0, 0);
    }
};
