class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }

        int maxLen = 0;
        for (int num : nums) {
            if (!numSet.contains(num - 1)) {
                int i = num;
                int len = 1;
                i++;
                while (numSet.contains(i++)) {
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
