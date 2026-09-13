class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currNums;
        backtracking(nums, target, currNums);
        return res;
    }

private:
    vector<vector<int>> res;
    void backtracking(vector<int> &nums, int target, vector<int> &currNums) {
        int total = accumulate(currNums.begin(), currNums.end(), 0);
        if(total == target) {
            res.push_back(currNums);
            return;
        }

        if (total > target) {
            return;
        }

        for (int num : nums) {
            if (currNums.size() && num < currNums.back()) {
                continue;
            }
            currNums.push_back(num);
            backtracking(nums, target, currNums);
            currNums.pop_back();
        }
    }
};
