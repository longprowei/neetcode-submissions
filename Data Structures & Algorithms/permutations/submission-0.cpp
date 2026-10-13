class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<int>& used, unordered_set<int>& unused) {
        if (used.size() == nums.size()) {
            res.push_back(used);
            return;
        }

        for (auto num : unused) {
            used.push_back(num);
            unordered_set<int> newUnused = unused;
            newUnused.erase(num);
            backtracking(nums, used, newUnused);
            used.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used;
        unordered_set<int> unused(nums.begin(), nums.end());
        backtracking(nums, used, unused);
        return res;
    }
};
