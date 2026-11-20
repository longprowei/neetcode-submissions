class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        using State = tuple<int, int, int>; // [weight, row, col]
        int n = grid.size();
        vector<int> dist(n * n, INT_MAX); // not tatal weight but the max value along the path
        vector<int> pred(n * n);
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(grid[0][0], 0, 0);
        dist[0] = grid[0][0];
        pred[0] = -1;

        const pair<int, int> delta[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            int pos = r * n + c;
            if (d > dist[pos]) continue;
            
            for (auto [dr, dc] : delta) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                int nPos = nr * n + nc;
                int nDist = max(grid[nr][nc], d);
                if (dist[nPos] > nDist) {
                    pred[nPos] = pos;
                    dist[nPos] = nDist;
                    pq.emplace(nDist, nr, nc);
                }
            }
        }

        return dist[n * n - 1];
    }
};
