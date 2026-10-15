class Solution {
    static constexpr pair<int, int> DELTA[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& seen, int i, int j) {
        if (seen[i][j]) {
            return 0;
        }

        seen[i][j] = true;
        int area = 1;
        for (auto [dr, dc] : DELTA) {
            int nr = dr + i;
            int nc = dc + j;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                area += dfs(grid, seen, nr, nc);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    int area = dfs(grid, seen, i, j);
                    cerr << i << "," << j << endl;
                    cerr << "area is " << area << endl;
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
