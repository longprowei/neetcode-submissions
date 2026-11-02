class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int reset = 0;
        int held = INT_MIN;
        int sold = INT_MIN;

        for (const int& price : prices) {
            int oldSold = sold;
            sold = held + price;
            held = max(reset - price, held);
            reset = max(reset, oldSold);
        }

        return max(sold, reset);
    }
};
