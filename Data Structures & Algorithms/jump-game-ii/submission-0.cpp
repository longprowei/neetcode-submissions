class Solution {
private:
    unordered_map<int, unordered_map<int, int>> mem;
    int minJumps(vector<int>& nums, int currIndex, int currJumps) {
        if (currIndex >= nums.size() - 1) {
            return currJumps;
        }

        if (mem.contains(currIndex) && mem[currIndex].contains(currJumps)) {
            return mem[currIndex][currJumps];
        }

        int jumps = INT_MAX;
        for (int j = 1; j <= nums[currIndex]; j++) {
            jumps = min(jumps, minJumps(nums, currIndex + j, currJumps + 1));
        }
        return mem[currIndex][currJumps] = jumps;
        return jumps;
    }
public:
    int jump(vector<int>& nums) {
        return minJumps(nums, 0, 0);
    }
};
