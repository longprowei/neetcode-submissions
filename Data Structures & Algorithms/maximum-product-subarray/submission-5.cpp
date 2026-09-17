class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n + 1, 1);
        vector<int> suffixProduct(n + 1, 1);
        int res = nums[0];
        for (int i = 1; i <= n; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
            suffixProduct[i] = suffixProduct[i - 1] * nums[n - i];
            res = max({res, prefixProduct[i], suffixProduct[i]});
            if (prefixProduct[i] == 0) {
                prefixProduct[i] = 1;
            }

            if (suffixProduct[i] == 0) {
                suffixProduct[i] = 1;
            }
        }
        
        return res;
    }
};
