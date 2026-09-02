class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[-nums[i]] = i; 
        }

        set<vector<int>> resSet;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                if (numMap.contains(sum)) {
                    int index = numMap[sum];
                    if (index == i || index == j) {
                        continue;
                    }

                    vector<int> triplet{-sum, nums[i], nums[j]};
                    sort(triplet.begin(), triplet.end());
                    resSet.insert(triplet);
                }
            }
        }

        return vector<vector<int>>(resSet.begin(), resSet.end());
    }
};
