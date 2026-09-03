class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n, numeric_limits<int>::max());
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], prices[i - 1]);
        }

        int ret = 0;
        // as a seller
        for (int i = 1; i < n; i++) {
            ret = max(ret, prices[i] - prefixMin[i]);
        }

        return ret;
    }
};
