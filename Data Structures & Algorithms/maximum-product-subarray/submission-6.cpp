class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefixProduct = 1;
        int suffixProduct = 1;
        int res = nums[0];
        for (int i = 1; i <= n; i++) {
            prefixProduct *= nums[i - 1];
            suffixProduct *= nums[n - i];
            res = max({res, prefixProduct, suffixProduct});
            if (prefixProduct == 0) {
                prefixProduct = 1;
            }

            if (suffixProduct == 0) {
                suffixProduct = 1;
            }
        }
        
        return res;
    }
};
