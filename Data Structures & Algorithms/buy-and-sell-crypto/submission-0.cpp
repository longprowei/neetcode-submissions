class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                ret = max(ret, prices[j] - prices[i]);
            }
        }

        return ret;
    }
};
