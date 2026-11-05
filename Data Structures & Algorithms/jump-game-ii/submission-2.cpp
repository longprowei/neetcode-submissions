class Solution {
public:
    int jump(vector<int>& nums) {
        int currIndex = nums.size() - 1;
        int jumps = 0;
        while (currIndex != 0) {
            // find the first index which can jump to the currIndex;
            for (int i = 0; i < currIndex; i++) {
                if (i + nums[i] >= currIndex) {
                    currIndex = i;
                    jumps++;
                    break;
                }
            }
        }
        return jumps;
    }
};