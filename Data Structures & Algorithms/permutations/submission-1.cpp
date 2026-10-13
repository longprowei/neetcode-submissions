class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<int>& used, int mask) {
        if (used.size() == nums.size()) {
            res.push_back(used);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                used.push_back(nums[i]);
                backtracking(nums, used, mask | (1 << i));
                used.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used;
        backtracking(nums, used, 0);
        return res;
    }
};
