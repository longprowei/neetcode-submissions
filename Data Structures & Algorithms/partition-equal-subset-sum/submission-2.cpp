class Solution {
private:
    unordered_map<int, unordered_map<int, bool>> mem;
    bool canPartition(vector<int>& nums, int numSum, int i) {
        if (i < 0 || numSum < 0) {
            return false;
        }

        if (numSum == 0 || numSum == nums[i]) {
            return true;
        }
        
        if (mem.contains(numSum) && mem[numSum].contains(i)) {
            return mem[numSum][i];
        }

        bool ret = canPartition(nums, numSum, i - 1) || canPartition(nums, numSum - nums[i], i - 1);
        mem[numSum][i] = ret;

        return ret;
    }
public:
    bool canPartition(vector<int>& nums) {
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if (numSum % 2 != 0) {
            return false;
        }
        return canPartition(nums, numSum / 2, nums.size() - 1);
    }
};
