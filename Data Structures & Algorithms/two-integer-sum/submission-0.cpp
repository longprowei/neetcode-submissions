class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;

        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int otherNum = target - nums[i];
            if (numMap.contains(otherNum)) {
                ret.push_back(numMap[otherNum]);
                ret.push_back(i);
                break;
            } else {
                numMap[nums[i]] = i;
            }
        }
        return ret;
    }
};
