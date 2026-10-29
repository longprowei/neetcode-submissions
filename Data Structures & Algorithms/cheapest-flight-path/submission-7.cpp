class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> nextPrices = prices;
            for (auto& flight : flights) {
                int srcCity = flight[0];
                int distCity = flight[1];
                int price = flight[2];

                if (prices[srcCity] == INT_MAX) {
                    continue;
                }

                if (prices[srcCity] + price < nextPrices[distCity]) {
                    nextPrices[distCity] = prices[srcCity] + price;
                }
            }
            prices = move(nextPrices);
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
