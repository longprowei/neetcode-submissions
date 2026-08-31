class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixProd(len + 1);
        vector<int> suffixProd(len + 1);
        prefixProd[0] = 1;
        suffixProd[0] = 1;

        for (int i = 1; i <= len; i++) {
            prefixProd[i] = prefixProd[i - 1] * nums[i - 1];
            suffixProd[i] = suffixProd[i - 1] * nums[len - i];
        }

        vector<int> result;
        for (int i = 0; i < len; i++) {
            result.push_back(prefixProd[i] * suffixProd[len - i - 1]);
        }
        return result;
    }
};
