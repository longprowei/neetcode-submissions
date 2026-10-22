class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>()); // dist, pointIndex

        // add edges between every points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].emplace_back(dist, j);
                adj[j].emplace_back(dist, i);
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0, 0); // start from point at index 0;
        vector<bool> visited(n, false);
        int cost = 0;
        while (!pq.empty()) {
            auto [dist, i] = pq.top();
            pq.pop();

            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            cost += dist;
            for (auto [d, j] : adj[i]) {
                pq.emplace(d, j);
            }
        }

        return cost;
    }
};
