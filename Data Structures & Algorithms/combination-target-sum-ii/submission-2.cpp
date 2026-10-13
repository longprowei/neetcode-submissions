class Solution {
private:
    vector<vector<int>> res;
    vector<int> numCounter;

    void genCombination(vector<int>& nums, int target, int i, vector<int>& curr, int currSum) {
        if (currSum == target) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }

            if (nums[j] + currSum > target) {
                break;
            }
            curr.push_back(nums[j]);
            genCombination(nums, target, j + 1, curr, currSum + nums[j]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        genCombination(candidates, target, 0, curr, 0);
        return res;
    }
};
