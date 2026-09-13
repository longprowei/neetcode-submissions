class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> currNums;
        dfs(nums, target, currNums, 0, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, int target, vector<int> &currNums, int total, int i) {
        if(total == target) {
            res.push_back(currNums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target) {
                return;
            }
            currNums.push_back(nums[j]);
            dfs(nums, target, currNums, total + nums[j], j);
            currNums.pop_back();
        }
    }
};
