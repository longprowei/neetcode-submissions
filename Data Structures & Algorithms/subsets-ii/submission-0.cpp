class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int i, vector<int> &subset) {
        res.push_back(subset);

        if (i >= nums.size()) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }

            subset.push_back(nums[j]);
            backtracking(nums, j + 1, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, subset);
        return res;
    }
};
