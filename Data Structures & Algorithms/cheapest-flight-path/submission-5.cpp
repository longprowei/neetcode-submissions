class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>()); // (price, dst)

        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[2], flight[1]);
        }

        using State = tuple<int, int, int>; // (price, node, stopsLeft);
        priority_queue<State, vector<State>, greater<State>> pq; 
        pq.emplace(0, src, 0);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        while (!pq.empty()) {
            auto [price, u, stops] = pq.top();
            pq.pop();
            if (u == dst) {
                return price;
            }

            if (dist[u][stops] == INT_MAX) {
                dist[u][stops] = price;
                for (auto [p, v] : adj[u]) {
                    if (stops <= k && dist[v][stops + 1] == INT_MAX) {
                        pq.emplace(p + price, v, stops + 1);
                    }
                }
            }
        }

        return -1;
    }
};
