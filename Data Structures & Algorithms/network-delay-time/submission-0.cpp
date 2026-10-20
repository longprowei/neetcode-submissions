class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int,int>>()); // [weight, node]

        for (auto time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].emplace_back(t, v);
        }

        const int INF = 1e9 + 7;
        vector<int> minTime(n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; // [path, node];
        pq.emplace(0, k);
        int res = -1;
        int nodeCount = 0;
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if (minTime[u] == INF) {
                minTime[u] = t;
                res = max(res, t);
                nodeCount++;
                for (auto [w, v] : adj[u]) {
                    pq.emplace(t + w, v);
                }
            }
        }

        return nodeCount == n ? res : -1;
    }
};
