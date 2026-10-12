class Solution {
private:
    vector<vector<int>> res;
    void addSubset(vector<int>& nums, vector<int> &curr, int currIndex) {
        if (currIndex == nums.size()) {
            return;
        }

        res.push_back(curr);
        for (int i = currIndex + 1; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            addSubset(nums, curr, i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> start;
        addSubset(nums, start, -1);
        return res;
    }
};
