class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> appearedNum;
        for (int n : nums) {
            if (appearedNum.contains(n)) {
                return true;
            }

            appearedNum.insert(n);
        }

        return false;
    }
};