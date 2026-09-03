class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n, numeric_limits<int>::max());
        vector<int> suffixMax(n, -1);
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], prices[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], prices[i + 1]);
        }

        int ret = 0;
        // as a seller
        for (int i = 0; i < n - 1; i++) {
            ret = max(ret, suffixMax[i] - prices[i]);
        }

        // as a buyer
        for (int i = 1; i < n; i++) {
            ret = max(ret, prices[i] - prefixMin[i]);
        }

        return ret;
    }
};
