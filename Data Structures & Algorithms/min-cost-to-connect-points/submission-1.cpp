class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        int edges = 0;
        int node = 0;
        int totalCost = 0;
        int nextNode = -1;
        dist[0] = 0;
        while (edges < n - 1) {
            visited[node] = true;
            nextNode = -1;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    continue;
                }

                int currDist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                dist[i] = min(dist[i], currDist); // dist[i] is the shortest distance from other nodes
                if (nextNode == -1 || dist[i] < dist[nextNode]) {
                    nextNode = i;
                }
            }
            totalCost += dist[nextNode];
            node = nextNode;
            edges++;
        }

        return totalCost;
    }
};
