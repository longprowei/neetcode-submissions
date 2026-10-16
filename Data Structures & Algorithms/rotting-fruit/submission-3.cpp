class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int freshCount = 0;
        queue<tuple<int, int, int>> q; // row, column, time
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j, 0);
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        const pair<int,int> delta[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int maxTime = 0;
        while (!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();

            for (auto [dr, dc] : delta) {
                int nr = dr + r;
                int nc = dc + c;
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.emplace(nr, nc, t + 1);
                    maxTime = max(maxTime, t + 1);
                    freshCount--;
                }
            }
        }

        return freshCount > 0 ? -1 : maxTime;
    }
};
