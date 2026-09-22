class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int MAX_NUMS_LEN = 1001;
        bitset<MAX_NUMS_LEN> numSet;
        for (auto num : nums) {
            numSet.set(num);
        }

        for (int i = 0; i < nums.size() + 1; i++) {
            if (!numSet[i]) {
                return i;
            }
        }
        return 0;
    }
};
